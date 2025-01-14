#!/bin/bash
echo "Bash version ${BASH_VERSION}"

if(($1 <= $2))
then
  r=$1
  for ((;r<=$2;r++))
  do
    i=0
    for ((;i<$4;))
    do
      num_children=$(pgrep -c -P$$)
      for ((;i<$4 && num_children<$5;))
      do
        python3 partialsatmp.py -nr $r -sl $3 -bl $4 -cb $i &
        num_children=$(pgrep -c -P$$)
        ((i++))
      done
      wait -n
    done
    wait

    cat result_$4_nr_"$r"_bit0.txt > sum_result_$4_nr_"$r".txt
    for ((i=1;i<$4;i=i+1)) 
    do
      cat result_$4_nr_"$r"_bit$i.txt >> sum_result_$4_nr_"$r".txt
    done
    rm result_$4_nr_$r_*
    rm sonic_$4_nr_$r_*
  done
else
  r=$1
  for ((;r>=$2;r--))
  do
    i=0
    for ((;i<$4;))
    do
      num_children=$(pgrep -c -P$$)
      for ((;i<$4 && num_children<$5;))
      do
        python3 partialsatmp.py -nr $r -sl $3 -bl $4 -cb $i &
        num_children=$(pgrep -c -P$$)
        ((i++))
      done
      wait -n
    done
    wait

    cat result_$4_nr_"$r"_bit0.txt > sum_result_$4_nr_"$r".txt
    for ((i=1;i<$4;i=i+1)) 
    do
      cat result_$4_nr_"$r"_bit$i.txt >> sum_result_$4_nr_"$r".txt
    done
    rm result_$4_nr_$r_*
    rm sonic_$4_nr_$r_*
  done
fi