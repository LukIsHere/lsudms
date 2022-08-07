#include "lsudms.hpp"
#include <iostream>
#include <fstream>
using namespace  std;
void ums::connect(){
    cout << "lsudms connected" << endl;
}
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

            //list
            //string value
            ums::list::list(){

            };
            ums::list::list(string v){

            };
            //work with list
            void ums::list::push(string v){

            };
            void ums::list::remove(string v){

            };
            bool ums::list::include(string v){
                return true;
            };
            void ums::list::forEach(std::function<void(string v)> fun){

            };
            //export
            string ums::list::getS(){
                return string("hi");
            };



            //var
            //string value;
            ums::var::var(){

            };
            ums::var::var(string v){

            };
            ums::var::var(int v){

            };
            ums::var::var(bool v){

            };
            ums::var::var(list v){

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
                return list();
            };
            //work with values
            void ums::var::Iadd(int toAdd){

            };
            void ums::var::Sappend(string toAppend){

            };
            void ums::var::Bnegate(){

            };
            void ums::var::Lpush(string v){

            };
            void ums::var::Lremove(string v){

            };
            bool ums::var::Linclude(string v){
                return true;
            };
            void ums::var::LforEach(function<void(string v)> fun){

            };
            //set values
            void ums::var::set(string v){

            };
            void ums::var::set(int v){

            };
            void ums::var::set(bool){

            };
            void ums::var::set(ums::list v){
                
            };



            //user
            //map<string,var> data;
            ums::user::user(){

            };
            ums::user::user(string dt){

            };
            //set values
            void ums::user::set(string name,string val){

            };
            void ums::user::set(string name,int val){

            };
            void ums::user::set(string name,bool val){

            };
            //work with values
            void ums::user::Iadd(string name,int toAdd){

            };
            void ums::user::Sappend(string name,string toAppend){

            };
            void ums::user::Bnegate(string name){

            };
            void ums::user::Lpush(string name,string v){

            };
            void ums::user::Lremove(string name,string v){

            };
            bool ums::user::Linclude(string name,string v){
                return true;
            };
            void ums::user::LforEach(string name,function<void(string v)> fun){

            };
            //get valuse
            string ums::user::gets(string name){
                return string("hi");
            };
            int ums::user::geti(string name){
                return 0;
            };
            bool ums::user::getb(string name){
                return true;
            };
            ums::list ums::user::getl(string name){
                return list();
            };



            //db
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

            };
            void ums::db::load(string loc){

            };
            //get user pointer
            ums::user * ums::db::get(int64_t id){
                return &(data[id]);
            };

            //cmd
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