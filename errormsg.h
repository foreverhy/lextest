#include <string>
#include <fstream>
#include <list>
namespace vlex{

class errormsg{
  public:
    static bool any_errors;
    static void newline();
    static int tokpos;
    static void error(int, std::string, ...);
    static void impossible(std::string);
    static void reset(std::string filename);
    static std::ifstream yyin;

  private:
    static std::string file_name;
    static int line_num;
    static std::list<int> line_pos;

};


}// namespace vlex
