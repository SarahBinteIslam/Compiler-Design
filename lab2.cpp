#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

bool separatorCheck(char ch)
{
    string value = " ,;(){}[]";
    for(int i=0; i<value.length(); i++)
        if(ch==value[i])
        return true;
    return false;
}

bool operatorCheck(char ch)
{
    string value = "+-*/<>=!";
    for(int i=0; i<value.length(); i++)
        if(ch==value[i])
        return true;
    return false;
}
bool keywordCheck(string s)
{
    string keyword[] = {"auto","break","case","char","const","continue","default",
                        "do","double","else","enum","extern","float","for","if",
                        "int","long","register","return","short","signed","sizeof",
                        "static","struct","switch","case","typeof","union","unsigned",
                        "void","while"};
    for(int i=0; i<(sizeof(keyword)/sizeof(string)); i++)
        if(s==keyword[i])
           return true;

    return false;

}
bool identifierCheck(string s)
{
    bool valid = true;

    if(keywordCheck(s))
        valid = false;

    if(keywordCheck(s))
        valid = false;

    if(valid)
        if((s[0] >= '0')&&(s[0] <= '9'))
            valid = false ;
    if (valid)
        for(int i =0 ; i<s.length(); i++)
          if(((s[i]>='a')&&(s[i]<='z'))||((s[i]>='A')&&(s[i]<='Z'))||((s[i]>='0')&&(s[i]<='9'))||(s[i]== '_'))
               continue;
    else
    {
        valid = false;
        break;
    }
 return valid;
}

bool numberCheck(string s)
{
    bool valid = true;
    for(int i=0;i<s.length() ; i++)
        if((s[i]>='0')&&(s[i]<='9')||(s[i]=='.'))
             continue;
    else
    {
        valid = false;
        break;
    }
    return valid;
}

void tokenizer (string s)
{
    vector <string> tokens;
    string token = "";

    for(int i=0; i<s.length(); i++)
    {
        if(separatorCheck(s[i]))
        {
            if(token!="")
            {
                //token.push_back(s[i]);
                tokens.push_back(token);

            }
            token = "";


        }
    else if (operatorCheck(s[i]))
    {
        if (token!= "")
        {
            tokens.push_back(token);
            token = "";
        }
        token.push_back(s[i]);
        tokens.push_back(token);
        token = "";

    }
    else
        token.push_back(s[i]);
    }
    if(token != "")
    {
        tokens.push_back(token);
        token = "";
    }


    for(int i=0; i<tokens.size(); i++)
    {
        if(keywordCheck(tokens[i]))
            cout<<'\"'<<tokens[i]<<"\" is a keyword"<<endl;
        else if (operatorCheck(tokens[i][0]))
            cout<<'\"'<<tokens[i]<<"\" is a Operator"<<endl;
        else if(identifierCheck(tokens[i]))
            cout<<'\"'<<tokens[i]<<"\" is a Identifier"<<endl;
        else if (numberCheck(tokens[i]))
            cout<<'\"'<<tokens[i]<<"\" is a Constant"<<endl;
        else
            cout<<'\"'<<tokens[i]<<"\" is a Invalid Identifier"<<endl;
    }
}

int main()

{
    ifstream file;
    string line;

    file.open("lab2.c");
    while (file) {
        getline(file, line);
        tokenizer(line);
    }
    file.close();
    return 0;
}

