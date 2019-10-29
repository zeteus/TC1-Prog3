make

echo
echo "--- ERRO 1: ---"
make run_e11 | grep 'Error 1'
make run_e12 | grep 'Error 1'
make run_e13 | grep 'Error 1'
make run_e14 | grep 'Error 1'
echo

echo "--- ERRO 2: ---"
make run_e21 | grep 'Error 2'
make run_e22 | grep 'Error 2'
make run_e23 | grep 'Error 2'
make run_e24 | grep 'Error 2'
make run_e25 | grep 'Error 2'
make run_e26 | grep 'Error 2'
make run_e27 | grep 'Error 2'
make run_e28 | grep 'Error 2'
make run_e29 | grep 'Error 2'
make run_e293 | grep 'Error 2'
echo

echo "--- ERRO 3: ---"
make run_e32 | grep 'Error 3'
make run_e33 | grep 'Error 3'
make run_e34 | grep 'Error 3'
make run_e35 | grep 'Error 3'
echo
