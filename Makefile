ss_gcc = /usr/local/3rdparty/simplescalar/bin/sslittle-na-sstrix-gcc
ss_as = /usr/local/3rdparty/simplescalar/bin/sslittle-na-sstrix-as
ss_ld = /usr/local/3rdparty/simplescalar/bin/sslittle-na-sstrix-ld
ss_strip = /usr/local/3rdparty/simplescalar/bin/sslittle-na-sstrix-strip
ss_objdump = /usr/local/3rdparty/simplescalar/bin/sslittle-na-sstrix-objdump

######################## init file generation ##############################
init.o : init.s 
	$(ss_as) init.s -o init.o


########################  sort test ###########################
sort.o : sort.c Makefile
	$(ss_gcc) -O0 -Wall -S sort.c -o sort.s 
	sed -i '/\<reorder\>/ d' sort.s
	sed -i '/__main/ d' sort.s
	$(ss_as) -nocpp -EL sort.s -o sort.o

ld_sort : init.o sort.o script.x
	$(ss_ld) -S -T ./script.x  init.o sort.o -o ld_sort
	$(ss_objdump) -D --disassemble-zeroes ld_sort > ld_sort.dis

strip_sort : ld_sort
	$(ss_strip) -s ld_sort -o strip_sort

sort.dis : strip_sort
	$(ss_objdump) -D --disassemble-zeroes --no-show-raw-insn strip_sort > sort.dis

sort: sort.dis
	perl dis2insn.pl sort.dis 

#	cp inst_mem.code ../sim
#	cp data_mem.data ../sim
#	cp inst_mem_init.v ../src
#	cp data_mem_init.v ../src


########################  laplace test ###########################
laplace.o : laplace.c Makefile
	$(ss_gcc) -O0 -Wall -S laplace.c -o laplace.s 
	sed -i '/\<reorder\>/ d' laplace.s
	sed -i '/__main/ d' laplace.s
	$(ss_as) -nocpp -EL laplace.s -o laplace.o

ld_laplace : init.o laplace.o script.x
	$(ss_ld) -S -T ./script.x  init.o laplace.o -o ld_laplace
	$(ss_objdump) -D --disassemble-zeroes --no-show-raw-insn ld_laplace > ld_laplace.dis

strip_laplace : ld_laplace
	$(ss_strip) -s ld_laplace -o strip_laplace

laplace.dis : strip_laplace
	$(ss_objdump) -D --disassemble-zeroes --no-show-raw-insn strip_laplace > laplace.dis

laplace: laplace.dis
	perl dis2insn.pl laplace.dis 


########################  Fibonacci test ###########################
Fibonacci.o : Fibonacci.c Makefile
	$(ss_gcc) -O0 -Wall -S Fibonacci.c -o Fibonacci.s 
	sed -i '/\<reorder\>/ d' Fibonacci.s
	sed -i '/__main/ d' Fibonacci.s
	$(ss_as) -nocpp -EL Fibonacci.s -o Fibonacci.o

ld_Fibonacci : init.o Fibonacci.o script.x
	$(ss_ld) -S -T ./script.x  init.o Fibonacci.o -o ld_Fibonacci
	$(ss_objdump) -D --disassemble-zeroes --no-show-raw-insn ld_Fibonacci > ld_Fibonacci.dis

strip_Fibonacci : ld_Fibonacci
	$(ss_strip) -s ld_Fibonacci -o strip_Fibonacci

Fibonacci.dis : strip_Fibonacci
	$(ss_objdump) -D --disassemble-zeroes --no-show-raw-insn strip_Fibonacci > Fibonacci.dis

Fibonacci: Fibonacci.dis
	perl dis2insn.pl Fibonacci.dis 

########################  bubble_sort test ###########################
bubble_sort.o : bubble_sort.c Makefile
	$(ss_gcc) -O0 -Wall -S bubble_sort.c -o bubble_sort.s 
	sed -i '/\<reorder\>/ d' bubble_sort.s
	sed -i '/__main/ d' bubble_sort.s
	$(ss_as) -nocpp -EL bubble_sort.s -o bubble_sort.o

ld_bubble_sort : init.o bubble_sort.o script.x
	$(ss_ld) -S -T ./script.x  init.o bubble_sort.o -o ld_bubble_sort
	$(ss_objdump) -D --disassemble-zeroes --no-show-raw-insn ld_bubble_sort > ld_bubble_sort.dis

strip_bubble_sort : ld_bubble_sort
	$(ss_strip) -s ld_bubble_sort -o strip_bubble_sort

bubble_sort.dis : strip_bubble_sort
	$(ss_objdump) -D --disassemble-zeroes --no-show-raw-insn strip_bubble_sort > bubble_sort.dis

bubble_sort: bubble_sort.dis
	perl dis2insn.pl bubble_sort.dis 

########################  loop test ###########################
loop.o : loop.c Makefile
	$(ss_gcc) -O0 -Wall -S loop.c -o loop.s 
	sed -i '/\<reorder\>/ d' loop.s
	sed -i '/__main/ d' loop.s
	$(ss_as) -nocpp -EL loop.s -o loop.o

ld_loop : init.o loop.o 
	$(ss_ld) init.o loop.o -o ld_loop
	$(ss_objdump) -D --disassemble-zeroes --no-show-raw-insn ld_loop > ld_loop.dis

########################  binarySearch test ###########################
binarySearch.o : binarySearch.c Makefile
	$(ss_gcc) -O0 -Wall -S binarySearch.c -o binarySearch.s 
	sed -i '/\<reorder\>/ d' binarySearch.s
	sed -i '/__main/ d' binarySearch.s
	$(ss_as) -nocpp -EL binarySearch.s -o binarySearch.o

#ld_binarySearch : init.o binarySearch.o script.x
ld_binarySearch : init.o binarySearch.o 
	#$(ss_ld) -S -T ./script.x  init.o binarySearch.o -o ld_binarySearch
	$(ss_ld) init.o binarySearch.o -o ld_binarySearch
	$(ss_objdump) -D --disassemble-zeroes --no-show-raw-insn ld_binarySearch > ld_binarySearch.dis

strip_binarySearch : ld_binarySearch
	$(ss_strip) -s ld_binarySearch -o strip_binarySearch

binarySearch.dis : strip_binarySearch
	$(ss_objdump) -D --disassemble-zeroes --no-show-raw-insn strip_binarySearch > binarySearch.dis

binarySearch: binarySearch.dis
	perl dis2insn.pl binarySearch.dis 

########################  cache instruction test ###########################
cache_test.o : cache_test.c Makefile
	$(ss_gcc) -O0 -Wall -S cache_test.c -o cache_test.s 
	sed -i '/\<reorder\>/ d' cache_test.s
	sed -i '/__main/ d' cache_test.s
	$(ss_as) -nocpp -EL cache_test.s -o cache_test.o

ld_cache_test : init.o cache_test.o script.x
	$(ss_ld) -S -T ./script.x  init.o cache_test.o -o ld_cache_test
	$(ss_objdump) -D --disassemble-zeroes --no-show-raw-insn ld_cache_test > ld_cache_test.dis

strip_cache_test : ld_cache_test
	$(ss_strip) -s ld_cache_test -o strip_cache_test

cache_test.dis : strip_cache_test
	$(ss_objdump) -D --disassemble-zeroes --no-show-raw-insn strip_cache_test > cache_test.dis

cache_test: cache_test.dis
	perl dis2insn.pl cache_test.dis 

################### Clean #######################
clean:
	rm -f *.o  *.s *.dis *.out *.bak ld_* strip_*
