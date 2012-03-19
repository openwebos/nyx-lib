#!/bin/sh

echo "Generating doxygen docs..."
doxygen ./Doxyfile &> /dev/null
echo "Done!"
