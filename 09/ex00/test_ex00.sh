#!/usr/bin/env bash
set -e

make -s

cat > input_ok.txt << 'EOF'
date | value
2011-01-03 | 3
2011-01-09 | 1
2012-01-11 | 1
EOF

cat > input_err.txt << 'EOF'
date | value
2012-01-11 | -1
2001-42-42
2012-01-11 | 2147483648
EOF

echo "== OK case =="
./btc input_ok.txt

echo "== ERR case =="
./btc input_err.txt || true

echo "== No args =="
./btc || true

echo "== Missing file =="
./btc nope.txt || true
