## Interx

> A toy, description domain-specific language for automata. Turing-complete.

Interx 是一种图灵完备的自动机描述语言，用于描述对话和交互。它允许用户通过文本输入和输出与自动机进行交互。

使用 Interx，用户可以在自动机的不同节点之间转移，并在节点间进行数据存储和计算。自动机的执行流程是，程序从特定的入口节点开始执行，每次执行时会在当前节点显示提示信息，并等待用户输入。用户输入后，程序会根据当前节点的转移规则进行转移，并在目标节点继续执行。如果转移规则中包含数据存储或计算操作，则会在转移过程中进行处理。

## 使用方法 Usage

### 安装依赖 Install dependencies

```bash
sudo apt install libboost-all-dev m4
```

```shell
wget http://ftp.gnu.org/gnu/bison/bison-3.8.2.tar.xz
tar -xvf bison-3.8.2.tar.xz
cd bison-3.8.2
./configure
make
sudo make install
```

```shell
```

### 构建 Build

```bash
git clone https://github.com/pluveto/interx
cd interx
make all
```

## 使用 Usage

```bash
./interx.out <file>
```

## 语法 Grammar

Interx 的语法主要由以下几种组成：

节点定义：每个节点都由一对中括号括起来，中括号内为节点名称。

```
[EntryNode]
```

节点属性：每个节点可以包含三种属性：提示信息、数据存储、转移规则。分别用 .Hint、.Storage 和 .Trans 标识。如：

```
[.Hint]
enter=("Hello, welcome to use bot.")
[.Storage]
out = (str2num($input) * 1.8 + 32)
outType = ("Celsius")
[.Trans]
TempNode_Result = (true)
```

数据存储：在 .Storage 属性中，用户可以定义变量名称和变量值，并使用函数进行计算。如：

```
[.Storage]
out = (str2num($input) * 1.8 + 32)
outType = ("Celsius")
```

转移规则：在 .Trans 属性中，用户可以定义转移条件和目标节点，并使用函数进行判断。如：

```
[.Trans]
TempNode_Result = (str2num($input) > 0)
```

终止操作：在 .Trans 属性中，用户可以使用 $term 变量来终止程序的执行。如：

```
[.Trans]
$term = (uncond)
```


## 示例 Example

### 综合示例

下面实现了一个简单的聊天机器人，用户可以选择不同的功能，如查询天气、温度转换、BMI 计算等。

```ini
[EntryNode]
[.Hint]
enter= ("Hello, welcome to use bot. Please choose your action:
1. Query weather 
2. Temperature converter 
3. BMI calculator
Q. Exit
Example: 1")
[.Trans]
ExitNode = ($input eq "Q" )
WeatherNode = ($input eq "1" )
TempNode = ($input eq "2" )
BMINode = ($input eq "3" )

[WeatherNode]
[.Hint]
enter=("Today's weather is sunny.")
[.Trans]
EntryNode = (uncond)

[TempNode]
[.Hint]
enter=("Select conversion:
1. C to F
2. F to C
B. Go back")
[.Trans]
EntryNode = ($input eq "B" )
TempNode_CtoF = ($input eq "1" )
TempNode_FtoC = ($input eq "2" )

[TempNode_CtoF]
[.Hint]
enter=("Input temperature in degrees Celsius:")
[.Storage]
out = (str2num($input) * 1.8 + 32)
outType = ("Celsius")
[.Trans]
TempNode_Result = (true) 

[TempNode_FtoC]
[.Hint]
enter=("Input temperature in degrees Fahrenheit:")
[.Storage]
out = (str2num($input) - 32 / 1.8)
outType = ("Celsius")
[.Trans]
TempNode_Result = (true)

[TempNode_Result]
[.Hint]
enter=("The temperature in {load('outType')} is {load('out')}")
[.Trans]
EntryNode = (uncond)


[BMINode]
[.Hint]
enter=("Input height in meter:")
[.Storage]
height = (str2num($input))
[.Trans]
BMINode_Phase2 = (true) 

[BMINode_Phase2]
[.Hint]
enter=("Input weight in kg:")
[.Storage]
weight = (str2num($input))
height = (load('height'))
bmi = (weight / (height * height))
[.Trans]
BMINode_Result = (true) 

[BMINode_Result]
[.Hint]
enter=("Your BMI is {load('bmi')}")
[.Trans]
EntryNode = (uncond)

[ExitNode]
[.Hint]
enter = ("Goodbye!")
[.Trans]
$term = (uncond)
```

### 循环和条件

这是一个用于计算 1 到 N 的和的程序。

程序从 EntryNode 节点开始执行，每次执行时会提示用户输入一个数字 N。用户输入后，程序会将 N 转换为数字并存储在 N 变量中，并将 cur 和 sum 变量初始化为 0。然后程序转移到 LoopNode 节点开始循环执行。

在 LoopNode 节点中，程序会将 cur 变量加 1，并将当前的 cur 值加入 sum 变量中。然后程序根据 cur 变量与 N 变量的大小关系进行转移。如果 cur 大于等于 N，则转移到 EndNode 节点；如果 cur 小于 N，则继续在 LoopNode 节点执行。

当程序转移到 EndNode 节点时，循环结束，程序会显示 sum 变量的值，即 1 到 N 的和。然后程序终止执行。

```ini
[EntryNode]
[.Hint]
enter=("This is a program to calculate the sum of 1 to N.
Input number N:")
[.Storage]
sum = 0
cur = 0
N = str2num($input)
[.Trans]
LoopNode = (true)

[LoopNode]
[.Storage]
N = load('N')
cur = load('cur') + 1
sum = load('sum') + cur
[.Trans]
EndNode = (cur >= N)
LoopNode = (cur < N)

[EndNode]
[.Hint]
enter=("The sum is: {load('sum')}")
[.Trans]
$term = (uncond)
```

## 代码说明

### Interpreter 类

|类成员|类型|说明|
|--- |--- |--- |
|root|TransUnit*|AST 的根节点|
|envs|std::unordered_map<Section*, Environment>|每个 section 有其自己的 environment，这是一个将 section 映射到 environment 的 map|
|nodes|std::unordered_map<std::string, Section*>|一个将 section name 映射到 section 的 index|
|prev|Section*|用来存储上一个节点，以便在下一个节点中使用 $prev|

|函数签名|说明|
|--- |--- |
|Interpreter(TransUnit* root)|构造函数，设置 root 节点|
|void init_env()|初始化 environment|
|void interpret()|解释 AST|
|std::pair<Section*, bool> find_uncond_node(Section* node)|返回 node 的 uncond 节点（如果存在），以及是否应该终止|
|Section* interpret_node(Section* node)|解释给定节点|
|std::string to_print(Environment* env, Expr* expr)|返回表达式的字符串形式|

说明：

+ TransUnit 为 AST 的节点类型
+ Environment 为解释器的环境类型
+ Expr 为表达式的基类
+ IDExpr 为表示标识符的表达式类型

Interpreter 类用于解释 AST，其中包含了每个 section 的 environment，以及将 section name 映射到 section 的 index。init_env() 函数用于初始化这些信息，interpret() 函数用于解释整个 AST。find_uncond_node() 函数返回给定节点的 uncond 节点（如果存在），以及是否应该终止，interpret_node() 函数用于解释单

### Environment 类


|成员|类型|说明|
|--- |--- |--|
|str_vals|std::unordered_map<std::string, std::string>| 表示存放的字符串值。|
|num_vals|std::unordered_map<std::string, double>|表示存放的双精度小数值。|
|bool_vals|std::unordered_map<std::string, bool>|表示存放的布尔值。|

|函数签名|成员介绍|
|--- |--- |
|Environment()|构造函数，初始化一个环境对象|
|EvalResult get(std::string name)|获取变量的值|
|bool set(std::string name, std::string value)|设置字符串类型的变量的值|
|bool set(std::string name, const char *value)|设置字符串类型的变量的值|
|bool set(std::string name, double value)|设置数字类型的变量的值|
|bool set(std::string name, bool value)|设置布尔类型的变量的值|
|bool set(std::string name, EvalResult value)|设置变量的值|
