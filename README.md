<h1>Intro</h1>
<p>This project contains multiple files written in C++</p>
<ul>
<li>Electron Configuration </li>
<li> Database </li>

# Electron Configuration 
This simply works on based in energy efficiency like the energy of the orbital.
It is based on only the orbitals of

> s,p,d,f

but according to neuclear physics it doesn't work on the higher atomic number molecule
it depends on
<ul>
  <li> Electron shielding
  </li>
  <li>Nuclear charge (Z)</li>
  <li>Relativistic effects (important in heavy atoms)</li>
</ul>


# database
this a simple c++ database of a little library using 'SQLITE3'
## Note
require SQLITE3
to install sqlite3 in your linux pc type
> sudo apt install sqlite3
## Play
to run the code type 
> sudo pkg install sqlite
</br>

> g++ test.cpp -o test -l sqlite3

</br>

> ./test

</br>
or
</br>

> g++ test.cpp -o test -l sqlite3
> ./test
