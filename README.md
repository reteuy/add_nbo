# add_nbo
  Assignment #2
## USAGE
```
$ echo -n -e \\x00\\x00\\x03\\xe8 > thousand.bin
$ echo -n -e \\x00\\x00\\x01\\xf4 > five-hundred.bin
$ ./add-nbo thousand.bin five-hundred.bin
```
**DESIRED OUTPUT** : 1000(0x3e8) + 500(0x1f4) = 1500(0x5dc)
