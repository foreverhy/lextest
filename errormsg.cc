/*
 * errormsg.cc - functions used in all phases of the compiler to give
 *              error messages about the Tiger program.
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include "util.h"
#include "errormsg.h"

namespace vlex{

// initialize static variables
bool errormsg::any_errors = false;
int errormsg::tokpos = 0;
std::ifstream errormsg::yyin;

std::string errormsg::file_name = "";
int errormsg::line_num = 1;
std::list<int> errormsg::line_pos;


void errormsg::newline(){
    ++line_num;
    line_pos.push_back(tokpos);
}

void errormsg::error(int pos, std::string msg, ...){
   va_list ap;
   auto num = line_num;

   any_errors = true;
   for(auto &line: line_pos){
        if("" != file_name){
            std::fprintf(stderr, "%s:", file_name.data());
        }
        if(line){
            std::fprintf(stderr, "%d.%d: ", num, pos - line);
        }
        va_start(ap, msg);
        std::vfprintf(stderr, msg.data(), ap);
        va_end(ap);
        std::fprintf(stderr, "\n");
   }
}




void errormsg::reset(std::string fname){
    any_errors = false;
    file_name = fname;
    line_num = 1;
    line_pos.clear();
    yyin.open(fname, std::ios::in);
    if(!yyin.is_open()){
        error(0, "cannot open");
        exit(1);
    }
}

}// namespace vlex

