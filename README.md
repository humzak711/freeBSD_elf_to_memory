*FOR EDUCATIONAL PURPOSES ONLY, WE DO NOT CONDONE ANY MISUSE OF THIS REPOSITORY, THE AUTHORS EXPECT NO LIABILITY FOR ANY MISUSE, YOU ARE RESPONSIBLE FOR YOUR OWN ACTIONS, THIS REPOSITORY WAS CREATED TO LEARN ABOUT LINUX AND FREEBSD DEVELOPMENT AND THE TCSH SCRIPTING LANGUAGE*

A tool for Linux which takes a given executable or .so ELF file, packs it into a new executable file which will execute the given executable or .so ELF file into memory via reflective elf injection<br>
Written in tcsh (Tenex C shell) and C<br>
**Injected .so's must contain an `__attribute__((constructor))` to be compatible as the `__attribute__((constructor))` will be the function executed once the .so is loaded into memory, see 
'examples/exampleSO1.c'**<br>

Dependencies: xxd, gcc<br>
To install dependencies: sudo tcsh setup.tcsh<br>
Usage: tcsh main.tcsh <src_ELF_path> <new_ELF_path><br>

How to install and setup:

if on arch:<br>
<code>pacman -S tcsh</code><br>
if on a debian based linux distribution:<br>
<code>sudo apt-get install tcsh</code><br>

<code>git clone https://github.com/humzak711/reflective_elf_injector.git<br>
cd reflective_elf_injector<br>
tcsh setup.tcsh</code><br>

to do:
- Add support for FreeBSD
 
