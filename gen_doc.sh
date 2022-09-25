#!/bin/sh

doxygen
doxybook2 --input doxygen/xml --output docs/doxybook --config doxybook2/config.json
# mkdocs build