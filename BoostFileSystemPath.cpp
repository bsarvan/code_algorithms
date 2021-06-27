//
//  main.cpp
//  BoostFileSystemPath
//
//  Created by Bharat Sarvan on 29/06/20.
//  Copyright © 2020 bsarvan. All rights reserved.
//

#include <boost/filesystem.hpp>
#include <iostream>

using namespace boost::filesystem;

int main()
{
  path p{"C:\\Windows\\System"};
  std::cout << p.root_name() << '\n';
  std::cout << p.root_directory() << '\n';
  std::cout << p.root_path() << '\n';
  std::cout << p.relative_path() << '\n';
  std::cout << p.parent_path() << '\n';
  std::cout << p.filename() << '\n';
}
