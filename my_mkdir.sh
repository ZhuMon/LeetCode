mkdir -p $1
cp -f Makefile $1/Makefile || exit 1
ln -sf .clang-format $1/ || exit 1
