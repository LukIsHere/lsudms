#include "lsudms.hpp"
#include <iostream>
#include <fstream>
using namespace  std;
//sprawdza czy biblioteka działa poprawnie
void ums::connect(){
    cout << "lsudms connected" << endl;
}
//konwertuje string na int64_t
int64_t ums::stoi64(string v){
    
    int64_t out = 0;
    int64_t te = 1;
    for (int i = 0; v.length() > i; ++i)
    {
        string charr;
        charr.push_back(v.at(v.length() -1 - i));
        out = stoi(charr) * te + out;
        te = te*10;
    }
    return out;
}

            //list - przechowuje zbiur wartość
            //string value
            ums::list::list(){
                value = "";
            };
            ums::list::list(string v){
                value = v;
            };
            //work with list
            void ums::list::push(string v){
                value.append(",");
                value.append(v);
            };
            void ums::list::remove(string v){
                string cur = "";
                string anal = value;
                int start = 0;
                int leng = 0;
                int fs;
                int fl;
                for (int i = 0; i < anal.length(); i++)
                {
                    if (anal.at(i) == ',')
                    {
                        if (cur == value)
                        {
                            fs = start;
                            fl = leng;
                        }
                        cur = "";
                        start = i + 1;
                        leng = 0;
                    }
                    else
                    {
                        leng++;
                        cur += anal.at(i);
                    }
                }
                if (cur == value)
                {
                    fs = start;
                    fl = leng;
                }
                string out = "";
                if (anal.at(fs + fl) == ',')
                {
                    fl++;
                }
                else if (anal.at(fs - 1) == ',')
                {
                    fs--;
                    fl++;
                }
                for (int i = 0; i < anal.length(); i++)
                {
                    if (i < fs || i > fs + fl - 1)
                    {
                        out += anal.at(i);
                    }
                }
                value = out;
            };
            bool ums::list::include(string v){
                bool out = false;
                string cur = "";
                string anal = value;
                for (int i = 0; i < anal.length(); i++)
                {
                    if (anal.at(i) == ',')
                    {

                        if (cur == value)
                        {
                            out = true;
                        }

                        cur = "";
                    }
                    else
                    {
                        cur += anal.at(i);
                    }
                }
                if (cur == value)
                {
                    out = true;
                }
                return out;
            };
            void ums::list::forEach(std::function<void(string v)> fun){
                string cur = "";
                string anal = value;
                for (int i = 0; i < anal.length(); i++)
                {
                    if (anal.at(i) == ',')
                    {
                        fun(cur);
                    }
                    else
                    {
                        cur += anal.at(i);
                    }
                }
                fun(cur);
            };
            string ums::list::get(int p){
                string cur = "";
                int id = 0;
                string anal = value;
                for (int i = 0; i < anal.length(); i++)
                {
                    if (anal.at(i) == ',')
                    {
                        if (id == p)
                        {
                            return cur;
                        }
                        else
                        {
                            cur = "";
                        }
                        id++;
                    }
                    else
                    {
                        cur += anal.at(i);
                    }
                }
                if (id == p)
                {
                    return cur;
                }
                return "";
            };
            int ums::list::size(){
                int out = 1;
                string anal = value;
                for (int i = 0; i < anal.length(); i++)
                {
                    if (anal.at(i) == ',')
                    {
                        out++;
                    }
                }
                return out;
            };
            //export
            string ums::list::getS(){
                return value;
            };



            //var - działa jako kilka wartość
            //bool exist;
            //string value;
            ums::var::var(){
                exist = false;
            };
            ums::var::var(string v){
                value = v;
                exist = true;
            };
            ums::var::var(int v){
                value = to_string(v);
                exist = true;
            };
            ums::var::var(bool v){
                if(v)value = "true";
                else value = "false";
                exist = true;
            };
            ums::var::var(list v){
                value = v.getS();
                exist = true;
            };
            //get values
            string ums::var::gstr(){
                return string("hi");
            };
            int ums::var::gint(){
                return 0;
            };
            bool ums::var::gbool(){
                return true;
            };
            ums::list ums::var::getl(){
                return list(value);
            };
            //work with values
            void ums::var::Iadd(int toAdd){
                try
                {
                    value = to_string(stoi(value)+toAdd);
                }
                catch(const std::exception& e)
                {
                    try
                    {
                        value = to_string(stoi64(value)+toAdd);
                    }
                    catch(const std::exception& e)
                    {
                        std::cerr << e.what() << '\n';
                    }
                }
            };
            void ums::var::Sappend(string toAppend){
                value.append(toAppend);
            };
            void ums::var::Bnegate(){
                if(value=="true") value="false";
                else value = "true";
            };
            void ums::var::Lpush(string v){
                list l = list(value);
                l.push(v);
                value = l.getS();
            };
            void ums::var::Lremove(string v){
                list l = list(value);
                l.remove(v);
                value = l.getS();
            };
            bool ums::var::Linclude(string v){
                return list(value).include(v);
            };
            void ums::var::LforEach(function<void(string v)> fun){
                list(value).forEach(fun);
            };
            //set values
            void ums::var::set(string v){
                value = v;
                exist = true;
            };
            void ums::var::set(int v){
                value = to_string(v);
                exist = true;
            };
            void ums::var::set(bool v){
                if(v)value = "true";
                else value = "false";
                exist = true;
            };
            void ums::var::set(ums::list v){
                value = v.getS();
                exist = true;
            };



            //user - przechowuje wartość
            //map<string,var> data;
            ums::user::user(){

            };
            ums::user::user(string dt){
                //to-do
            };
            //set values
            void ums::user::set(string name,string val){
                data[name] = var(val);
            };
            void ums::user::set(string name,int val){
                data[name] = var(val);
            };
            void ums::user::set(string name,bool val){
                data[name] = var(val);
            };
            //work with values
            void ums::user::Iadd(string name,int toAdd){
                data[name].Iadd(toAdd);
            };
            void ums::user::Sappend(string name,string toAppend){
                data[name].Sappend(toAppend);
            };
            void ums::user::Bnegate(string name){
                data[name].Bnegate();
            };
            void ums::user::Lpush(string name,string v){
                data[name].Lpush(v);
            };
            void ums::user::Lremove(string name,string v){
                data[name].Lremove(v);
            };
            bool ums::user::Linclude(string name,string v){
                return data[name].Linclude(v);
            };
            void ums::user::LforEach(string name,function<void(string v)> fun){
                data[name].LforEach(fun);
            };
            //get valuse
            string ums::user::gets(string name){
                return data[name].gstr();
            };
            int ums::user::geti(string name){
                return data[name].gint();
            };
            bool ums::user::getb(string name){
                return data[name].gbool();
            };
            ums::list ums::user::getl(string name){
                return data[name].getl();
            };
            string ums::user::getS(){
                return string("");//{"val":"key"} //to-do
            }



            //db - przechowuje użytkowników
            //string name;
            //map<int64_t,user> data;
            ums::db::db(){
                name = "";
            };
            ums::db::db(string n){
                name = n;
            };
            // save/load data from files
            // id:{"key":"value","key2":"value2"}
            void ums::db::save(string loc){
                //to-do
            };
            void ums::db::load(string loc){
                //to-do
            };
            //get user pointer
            ums::user * ums::db::get(int64_t id){
                return &(data[id]);
            };



            //cmd - pozwala analizować string pod kontem argumentów
            //string v;
            ums::cmd::cmd(){

            };
            ums::cmd::cmd(string value){
                v = value;
            };
            string ums::cmd::get(int p){
                int place = 0;
                string out = "";
                string finded;
                bool found = false;
                for(int i = 0; v.length()>i;i++){
                    if(v.at(i)==' '){
                        if(p==place){
                            finded = out;
                            place++;
                        }
                        else{
                            place++;
                            out = "";
                        }
                    }else{
                        out+=v.at(i);
                    }
                }
                if(p==place){
                            finded = out;
                            place++;
                        }
                return finded;
            };