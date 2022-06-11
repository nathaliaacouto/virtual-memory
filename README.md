# Virtual Memory Implementation :computer:
This exercise is based in *Designing a Virtual Memory Manager* shown in page P-51 of the book *Operating System Concepts by Silberschatz, A.* \
\
The idea of this implementation is to simulate the adition of a program - that is in the Virtual Memory - in the Main Memory. 

## How it works 🤔
The code separates the Page Number (PG) and Offset from the instruction, using that PG to read a value in the BACKING_STORE.bin (that here works as the Virtual Mem.). This "snippet" of the program is then added to the Main Memory. 

### Commands to test it :pencil:
- `git clone https://github.com/nathaliaacouto/virtual-memory.git`: Clone the repository in your machine
- `make`: Compile code
- `./vm addresses.txt fifo fifo`: Run code
- `make && ./vm addresses.txt fifo fifo`: Compile and Run code
- `make clean`: Clean project, delete the files created by the Makefile

### Files Index :file_folder:
- main: `nvc.c`
- all functions used: `functions.c`
- error treatment: `errors.c`
- files used in tests: `addresses.txt` and `BACKING_STORE.bin`
- files created by implementation: `correct.txt`

### Contact me :phone:
If you have any questions about the code, or issues you might have found, 
feel free to contact me through my github: [@nathaliaacouto](https://github.com/nathaliaacouto)

*Created by Nathália Couto*
