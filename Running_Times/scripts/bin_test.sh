# Testing the performance of the algorithms for n = 10,000,000, and varying the bins.

r=0
while [ $r -lt 100 ]; do
  for i in vector map multiset list bad_vec deque hash ; do
    bins=10
    t=no
    while [ $bins -le 100000 -a $t = no ]; do
      ans=`bin/range_$i 1 10000000 0 $bins 5 N`
      t=`echo $ans | awk '{ if ($4 < 5) print "no"; else print "yes" }'`
      echo $i $bins $ans
      if [ $bins -lt 1000 ]; then
        bins=$(($bins+10))
      else 
        bins=$(($bins+1000))
      fi
    done
  done
  r=$(($r+1))
done
