#!/bin/bash
echo "Bash version ${BASH_VERSION}"

b1=1
b2=256

echo "=======================================" > sum_result_"$1"_"$2".txt


r1=0
for ((;r1<$b1;r1++))
  do

  cd temp


  r2=0
  for ((;r2<$b2;r2++))
    do
      python3 ../ciphers/Sonic256/sonic.py --Rfw $1 --Rbw $2 --gfw $r1 --gbw $r2
  done

  cd ..



  r2=0
  for ((;r2<$b2;))
    do
      num_children=$(pgrep -c -P$$)
      for ((;r2<$b2 && num_children<$3;))
      do
        python3 autoguess.py --inputfile temp/relationfile_sonic_"$1"_"$2"_"$r1"_"$r2".txt --solver cp -cpopt 1 -mg 256 -ms 20  > temp/result_sonic_"$1"_"$2"_"$r1"_"$r2".txt &
        num_children=$(pgrep -c -P$$)
        ((r2++))
      done
      wait -n
  done
  wait


  r2=0
  for ((;r2<$b2;r2++))
  do
     echo "result_sonic_"$1"_"$2"_"$r1"_"$r2".txt" >> sum_result_"$1"_"$2".txt
    cat temp/result_sonic_"$1"_"$2"_"$r1"_"$r2".txt >> sum_result_"$1"_"$2".txt
    echo "=======================================" >> sum_result_"$1"_"$2".txt
  done

  rm temp/result_*
  rm temp/relationfile_sonic_*
done