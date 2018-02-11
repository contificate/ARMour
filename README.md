
TODO: get back to this (nathfreder)

# ARMour
A small attempt at writing an automatic ROP chainer for ARM.

Essentially, given a set of ROP gadgets acquired from an executable, chain them optimally for an arbitrary function call (that uses only argument registers r0-r3; perhaps utilisation of the stack could be theorised later on).

##### Example
### void function(int _a_, int _b_);
_a_ = **r0**, _b_ = **r1**

As noted, only functions accepting up to 4 arguments are being focused on.

##### Notes
I've not really theorised a good way of doing this so far. 
Some papers I've read on the subject suggest forming IR representations for each gadget block and then (essentially) bruteforcing order permutations by doing static analysis post-chaining (ordering) to check if required argument registers are live.

As for stack spilling and localised jump cycles (e.g. perhaps by forcing _cmp_ conditions to yield false), I'm not really concerned with those at the moment. It should be noted that being able to obsolete localised jumps is theoretically possible but would require much more rigorous static analysis. Being able to make use ROP gadgets that include localised jumps (by making the localised jumps redundant), could help defeat trivial defense mechanisms used to detect ROP chaining (such as CFI - Control Flow Integrity).

My approach isn't really consolidated but this repo exists solely as a way for me to backup anything I might want to consider working on more later on.

The general approach I've considered would be to find ROP gadgets via a linear sweep with backtracking (w/ group filtering). 

##### TODO: Write detailed description of ARM-specific approach to finding ROP gadgets and backtrack filtering via instruction groupings
