# Shell script to test the relative performance of list and vec when n = bins

bins=1000
while [ $bins -le 10000000 ]; do
  for i in list bad_vec ; do
    ans=`bin/range_$i 1 $bins 0 $bins 5 N`
    echo $ans $bins $i 
  done
  bins=$(($bins+1000))
done
