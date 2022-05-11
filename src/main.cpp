#include <iostream>
#include <fstream>

#include "json.hpp"

using namespace nlohmann;

int main(int argc, char* argv[])
{
  if ( argc < 2 )
  {
    std::cerr << "Usage: jf <files-to-indent>" << std::endl;
    return 1;
  }

  for ( int i = 1; i < argc; ++i )
  {
    try
    {
      std::ifstream in(argv[i]);
      json j = json::parse(in);
      in.close();
      std::ofstream out(argv[i]);
      out << j.dump(2);
      out.close();
    }
    catch ( const json::exception& exc )
    {
      std::cerr << "Error parsing file " << argv[i] << ": " << exc.what() << std::endl;
    }
  }

  return 0;
}