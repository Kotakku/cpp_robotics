#!/bin/sh

rm -rf docs/doxybook
mkdir docs/doxybook
doxygen
doxybook2 --input doxygen/xml --output docs/doxybook --config doxybook2/config.json
# mkdocs build