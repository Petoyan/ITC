

export LD_LIBRARY_PATH=./lib
echo "#############################################"
echo "############ Solved Gauss method ############"
./out_file/main_gauss.out
echo "#############################################"
echo "######## Solved Gauss-Seidel method #########"
./out_file/main_gauss_seidel.out
echo "#############################################"
echo "########### Solved Jakobi method ############"
./out_file/main_jakobi.out
echo "#############################################"
echo "################## Testing ##################"
echo "#############################################"
echo "#################  Gauss test ###############"
./test/gauss_integration_test.out
echo "#############################################"
echo "############# Gauss-Seidel test #############"
./test/gauss_seidel_integration_test.out
echo "#############################################"
echo "############### Jakobi teste ################"
./test/jakobi_integration_test.out
echo "#############################################"
