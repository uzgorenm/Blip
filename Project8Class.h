//
// Created by Mehmet Uzgoren on 7/29/22.
//

#ifndef QUIZ6_PROJECT8CLASS_H
#define QUIZ6_PROJECT8CLASS_H
#include <unordered_map>
#include <string.h>
#include <vector>
#include <iostream>
#include "Parse.h"
using namespace std;

int operate(int arg1, int arg2, string op){
    if(op == "+"){return arg1 + arg2;}
    if(op == "*"){return arg1 * arg2;}
    if(op == "/"){return arg1 / arg2;}
    if(op == "-"){return arg1 - arg2;}
    if(op == "%"){return arg1 % arg2;}
    if(op == "&&"){return arg1 && arg2;}
    if(op == "||"){if(arg1 || arg2){return 1;}else{return 0;}}
    if(op == "<"){if(arg1 < arg2){return 1;}else{return 0;}}
    if(op == ">"){if(arg1 > arg2){return 1;}else{return 0;}}
    if(op == "=="){if(arg1 == arg2){return 1;}else{return 0;}}
    if(op == "!="){if(arg1 != arg2){return 1;}else{return 0;}}
    if(op == "<="){if(arg1 <= arg2){return 1;}else{return 0;}}
    if(op == ">="){if(arg1 >= arg2){return 1;}else{return 0;}}
    if(op == "~"){return -1*arg1;}
    if(op == "!"){return !arg1;}
}

class Project8Class {
private:
    unordered_map<string, int> variables;
    int read_next = 0;
public:
    int parse(vector<string>& expr){
        string first = expr[0];
        expr.erase(expr.begin());
        if(first == "~" || first == "!"){
            if(expr[0].compare("+") != 0 && expr[0].compare("-")!=0 && expr[0].compare("*")!=0 && expr[0].compare("/")!=0 && expr[0].compare("%") != 0 && expr[0].compare("&&")!= 0 && expr[0].compare("||")!= 0 && expr[0].compare("<")!= 0 && expr[0].compare(">")!= 0 && expr[0].compare("==")!= 0 && expr[0].compare("!=")!= 0 && expr[0].compare("<=")!= 0 && expr[0].compare(">=")!=0 &&  expr[0].compare("~")!= 0 && expr[0].compare("!")!= 0) {
                if (variables.find(expr[0]) == variables.end()) {
                    int temp = stoi(expr[0]);
                    expr.erase(expr.begin());
                    return operate(temp, 0, first);
                } else {
                    return operate(variables[expr[0]], 0, first);
                }
            }
            else{
                int arg3 = parse(expr);
                return operate(arg3, 0, first);
            }
        }
        if(first.compare("+") != 0 && first.compare("-")!=0 && first.compare("*")!=0 && first.compare("/")!=0 && first.compare("%") != 0 && first.compare("&&")!= 0 && first.compare("||")!= 0 && first.compare("<")!= 0 && first.compare(">")!= 0 && first.compare("==")!= 0 && first.compare("!=")!= 0 && first.compare("<=")!= 0 && first.compare(">=")!=0 &&  first.compare("~")!= 0 && first.compare("!")!= 0){
            if(variables.find(first) == variables.end()){
                return stoi(first);
            }
            else{
                return variables[first];
            }
        }
        int arg1 = parse(expr);
        int arg2 = parse(expr);
        return operate(arg1, arg2, first);
    }
    void read() {
        read_next = 0;
        read_next_token();
        //As long as the program hasn't got to the end of the text file, keep parsing/ running
        while (next_token_type != END) {
            //If the next token is a //, skip the rest of the line as it is a comment
            if (next_token_type == SYMBOL && strcmp(next_token(), "//") == 0) {
                skip_line();
            }
            //If the next token is a name, it can be any of the following four:
            //set, var, output, text
            if (next_token_type == NAME) {
                //If the NAME Token is var, create a new variable
                //and set the value to the expression following
                if (strcmp(next_token(), "var") == 0) {
                    read_next_token();
                    //If the next token is a name, set the variable name to the next_token
                    if (next_token_type == NAME) {
                        string var_name = next_token();
                        if (variables.find(var_name) == variables.end()) {}
                        else{
                            cout<<"variable "<< var_name << " incorrectly re-initialized"<<endl;
                        }
                        read_next_token();
                        vector<string> expression;
                        int value = 2;
                        if(next_token_type == NUMBER){
                            value = 1;
                            while(value) {
                                expression.push_back(next_token());
                                read_next_token();
                                value--;
                            }
                            read_next = 1;
                        }
                        else{
                            if(strcmp(next_token(), "~") == 0 || strcmp(next_token(), "!") == 0){}
                            else{
                                value++;
                            }
                            while(value){
                                expression.push_back(next_token());
                                read_next_token();
                                if(next_token_type == SYMBOL && (strcmp(next_token(), "!") == 0 || strcmp(next_token(), "~") == 0)){
                                    value++;
                                }
                                else if(next_token_type == SYMBOL && strcmp(next_token(), "//") != 0){
                                    value+=2;
                                }
                                value--;
                            }
                            read_next = 1;
                        }
                        int var_value = parse(expression);
                        variables[var_name] = var_value;
                    }
                        //else If the next token is a
                    else if (next_token_type == SYMBOL) {
                        if (strcmp(next_token(), "//") == 0) {
                            skip_line();
                        } else {

                        }
                    }
                }
                if (strcmp(next_token(), "set") == 0) {
                    read_next_token();
                    if (next_token_type == NAME) {
                        string var_name = next_token();
                        if (variables.find(var_name) == variables.end()) {
                            cout << "variable " << var_name << " not declared" << endl;
                        }
                        read_next_token();
                        vector<string> expression;
                        int value = 2;
                        if(next_token_type == NUMBER){
                            value = 1;
                            while(value) {
                                expression.push_back(next_token());
                                read_next_token();
                                value--;
                            }
                            read_next = 1;
                        }
                        else {
                            if (strcmp(next_token(), "~") == 0 || strcmp(next_token(), "!") == 0) {}
                            else {
                                value++;
                            }
                            while (value) {
                                expression.push_back(next_token());
                                read_next_token();
                                if(next_token_type == SYMBOL && (strcmp(next_token(), "!") == 0 || strcmp(next_token(), "~") == 0)){
                                    value++;
                                }
                                else if(next_token_type == SYMBOL && strcmp(next_token(), "//") != 0){
                                    value+=2;
                                }
                                value--;
                            }
                            read_next = 1;
                        }
                        int var_value = parse(expression);
                        variables[var_name] = var_value;
                    }
                }
                    //If the NAME token is output, print the numbers
                if (strcmp(next_token(), "output") == 0) {
                    read_next_token();
                    vector<string> expression;
                    int value = 2;
                    if(next_token_type == NUMBER || next_token_type == NAME){
                        value = 1;
                        while(value) {
                            expression.push_back(next_token());
                            read_next_token();
                            value--;
                        }
                        read_next = 1;
                    }
                    else{
                        if(strcmp(next_token(), "~") == 0 || strcmp(next_token(), "!") == 0){}
                        else{
                            value++;
                        }
                        while(value){
                            expression.push_back(next_token());
                            read_next_token();
                            if(next_token_type == SYMBOL && (strcmp(next_token(), "!") == 0 || strcmp(next_token(), "~") == 0)){
                                value++;
                            }
                            else if(next_token_type == SYMBOL && strcmp(next_token(), "//") != 0){
                                value+=2;
                            }
                            value--;
                        }
                        read_next = 1;
                    }
                    int var_value = parse(expression);
                    cout<<var_value;
                }
                    //If the NAME token is text print
                if (strcmp(next_token(), "text") == 0) {
                    read_next_token();
                    string text = next_token();
                    cout << text;
                    if(read_next == 1){
                        read_next = 0;
                    }
                }
            }
            if(read_next == 1){
                read_next = 0;
            }
            else{
                read_next_token();
            }
        }
    }
//        read_next_token();
//        while(next_token_type != END){
//            if(next_token_type == NAME){
//                if(strcmp(next_token(), "var") == 0){
//                    read_next_token();
//                    if(next_token_type == NAME){
//                        string var_name = next_token();
//                        read_next_token();
//                        if(next_token_type == NUMBER){
//                            int var_value = token_number_value;
//                            this->variables[var_name] = var_value;
//                        }
//                        else{
//                            skip_line();
//                        }
//                    }
//                    else{
//                        skip_line();
//                    }
//                }
//                else if(strcmp(next_token(), "set") == 0){
//                    read_next_token();
//                    if(next_token_type == NAME) {
//                        string var_name = next_token();
//                        if (variables.find(var_name) == variables.end()) {
//                            cout << "Sorry, the variable " << var_name << " has not been initialized" << endl;
//                        } else {
//                            int var_value = 0;
//                            read_next_token();
//                            if (next_token_type == NUMBER) {
//                                var_value = token_number_value;
//                                this->variables[var_name] = var_value;
//                            } else {
//                                skip_line();
//                            }
//                        }
//                    }
//                    else{
//                        skip_line();
//                    }
//                }
//            }
//            read_next_token();
//        }

    void printvars(){
        cout<<endl;
        cout<<"Variable Table"<<endl;
        cout<< " ----"<<endl;
        for(auto i =variables.begin(); i!=variables.end(); i++){
            cout << "|" << i->first <<"|"<< i->second << "|" <<endl;
        }
        cout<< " ----"<<endl;
    }

};

void run(void){
    Project8Class variabletable;
    variabletable.read();
}

#endif //QUIZ6_PROJECT8CLASS_H
