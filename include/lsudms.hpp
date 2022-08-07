#pragma once
#include <map>
#include <string>
#include <iostream>
#include <functional>
//function<zwrot(argumenty)> func
namespace ums{
    void connect();
    int64_t stoi64(std::string v);
    class list{
        public:
            std::string value;
            list();
            list(std::string v);
            //work with list
            void push(std::string v);
            void remove(std::string v);
            bool include(std::string v);
            void forEach(std::function<void(std::string v)> fun);
            //export
            std::string getS();
    };
    class var{
        public:
            std::string value;
            var();
            var(std::string v);
            var(int v);
            var(bool v);
            var(list v);
            //get values
            std::string gstr();
            int gint();
            bool gbool();
            list getl();
            //work with values
            void Iadd(int toAdd);
            void Sappend(std::string toAppend);
            void Bnegate();
            void Lpush(std::string v);
            void Lremove(std::string v);
            bool Linclude(std::string v);
            void LforEach(std::function<void(std::string v)> fun);
            //set values
            void set(std::string v);
            void set(int v);
            void set(bool);
            void set(list v);
    };
    class user{
        public:
            std::map<std::string,var> data;
            user();
            user(std::string dt);
            //set values
            void set(std::string name,std::string val);
            void set(std::string name,int val);
            void set(std::string name,bool val);
            //work with values
            void Iadd(std::string name,int toAdd);
            void Sappend(std::string name,std::string toAppend);
            void Bnegate(std::string name);
            void Lpush(std::string name,std::string v);
            void Lremove(std::string name,std::string v);
            bool Linclude(std::string name,std::string v);
            void LforEach(std::string name,std::function<void(std::string v)> fun);
            //get valuse
            std::string gets(std::string name);
            int geti(std::string name);
            bool getb(std::string name);
            list getl(std::string name);
    };
    class db{
        public:
            std::string name;
            std::map<int64_t,user> data;
            db();
            db(std::string name);
            // save/load data from files
            // id:{"key":"value","key2":"value2"}
            void save(std::string loc);
            void load(std::string loc);
            //get user pointer
            user *get(int64_t id);
    };
    
    class cmd{
        public:
            std::string v;
            cmd();
            cmd(std::string value);
            std::string get(int p);
    };
}