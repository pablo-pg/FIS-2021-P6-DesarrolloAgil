#!/bin/bash

# Genrates documentation for C++ source code files, according
# to a Doxygen configuration file, located in current folder.

# Default name for a new Doxygen configuration file.
FILENAME=".doxygen-config"

# Check whether doxygen tool is already installed.
if [ "$(which doxygen)" != "" ]; then
  # Look for an existing format style file.
  if [ "$(find . -maxdepth 1 -type f -name $FILENAME)" = "" ]; then
    echo "No Doxygen configuration file was found"
    echo -n "Do you want to create one? (y/n) > "
    read generate

    # Check user input and generate a new format style file if so.
    if [ "$generate" = "y" ] || [ "$generate" = "Y" ]; then
      doxygen -g $FILENAME 1>/dev/null
    else
      echo "Mandatory: make a Doxygen configuration file to create documentation"
      exit 1
    fi
  fi
  
  # Perform formatting over desired files.
  if cd ../include; then
    doxygen ../tools/$FILENAME 1>/dev/null
    echo "Documentation for the source code has been generated!!!"
  fi
else
  echo "Mandatory: sudo apt install doxygen"
  exit 1
fi
