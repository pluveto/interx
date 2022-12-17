为下面的类用 Markdown 表格写一个说明。包括类成员、类成员的类型、函数签名、成员介绍等。

```cpp
class Environment {
    std::unordered_map<std::string, std::string> str_vals;
    std::unordered_map<std::string, double> num_vals;
    std::unordered_map<std::string, bool> bool_vals;

  public:
    Environment() {}
    /**
     * @brief Get the value of a variable
     */
    EvalResult get(std::string name) {
        if (str_vals.find(name) != str_vals.end()) {
            return EvalResult(str_vals[name]);
        } else if (num_vals.find(name) != num_vals.end()) {
            return EvalResult(num_vals[name]);
        } else if (bool_vals.find(name) != bool_vals.end()) {
            return EvalResult(bool_vals[name]);
        } else if (name == "true") {
            return ER_True;
        } else if (name == "false") {
            return ER_False;
        } else if (name == "zero") {
            return ER_Zero;
        } else {
            std::cerr << "undefined variable: " << name << std::endl;
            assert(false);
            return EvalResult();
        }
    }
    /**
     * @brief Set the value of a variable (string)
     */
    bool set(std::string name, std::string value) {
        auto old = str_vals.find(name);
        if (old != str_vals.end()) {
            old->second = value;
            return true;
        } else {
            str_vals[name] = value;
            return false;
        }
    }
    /**
     * @brief Set the value of a variable (const char *)
     */
    bool set(std::string name, const char *value) {
        auto old = str_vals.find(name);
        if (old != str_vals.end()) {
            old->second = value;
            return true;
        } else {
            str_vals[name] = value;
            return false;
        }
    }
    /**
     * @brief Set the value of a variable (number)
     */
    bool set(std::string name, double value) {
        auto old = num_vals.find(name);
        if (old != num_vals.end()) {
            old->second = value;
            return true;
        } else {
            num_vals[name] = value;
            return false;
        }
    }
    /**
     * @brief Set the value of a variable (bool)
     */
    bool set(std::string name, bool value) {
        auto old = bool_vals.find(name);
        if (old != bool_vals.end()) {
            old->second = value;
            return true;
        } else {
            bool_vals[name] = value;
            return false;
        }
    }
    /**
     * @brief Set the value of a variable (EvalResult)
     */
    bool set(std::string name, EvalResult value) {
        switch (value.type) {
        case ValType_STRING:
            return set(name, value.str_val);
        case ValType_NUMBER:
            return set(name, value.num_val);
        case ValType_BOOL:
            return set(name, value.bool_val);
        }
        return false;
    }
};
```