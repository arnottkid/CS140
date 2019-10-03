if [ $# -ne 1 ]; then
  echo 'usage: sh scripts/timer.sh program'
  exit 1
fi

suffix=""

while [ A"$suffix" != A000000000000000 ] ; do
  for i in 10 25 50 75 ; do
    n=$i"$suffix"
    rv=`echo $n | $1`
    count=`echo $rv | awk '{ print $4 }'`
    time=`echo $rv | awk '{ printf "%.0f", $6 }'`
    echo $rv
    if [ $time -ge 60 ]; then
      exit 0
    fi
  done
  suffix="$suffix"0
done
