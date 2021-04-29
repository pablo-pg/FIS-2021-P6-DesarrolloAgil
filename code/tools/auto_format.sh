#!/bin/bash

# Formats all C++ source code files, according to
# a .clang-format file, located in current folder.

# Default formatting style to be applied for a new .clang-format file.
STYLE=google

# Check whether clang-format tool is already installed.
if [ "$(which clang-format)" != "" ]; then
  # Look for an existing format style file.
  if [ "$(find . -maxdepth 1 -type f -name ".clang-format")" = "" ]; then
    echo "No format style file was found"
    echo -n "Do you want to create one (style=${STYLE})? (y/n) > "
    read generate

    # Check user input and generate a new format style file if so.
    if [ "$generate" = "y" ] || [ "$generate" = "Y" ]; then
      clang-format -style=$STYLE -dump-config > .clang-format
    else
      echo "Mandatory: create a format style file to allow formatting"
      exit 1
    fi
  fi
  
  # Perform formatting over desired files under include directory.
  clang-format -i -style=file ../include/*.h
  echo "Include: source code is now formatted!!!"
  
  # Perform formatting over desired files under src directory.
  clang-format -i -style=file ../src/*.cc
  echo "Include: source code is now formatted!!!"

else
  echo "Mandatory: sudo apt install clang-format"
  exit 1
fi
