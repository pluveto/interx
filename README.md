## interx

Description language for automata. Turing-complete.

## Example

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