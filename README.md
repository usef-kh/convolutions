# Convolutions

## Important links
- [Presentation](https://docs.google.com/presentation/d/1sHktguavhx-a1x_DG-631PH3XLJTdArvoRf-VFoI7yA/edit?usp=sharing)
- [Report]()

## Overview
This project experiments with running a 2D convolution in a variety of ways. 

The current available implementations here are:
- Serial
- OpenACC
- OpenMP
- Threading 

Each of these implementations and their makefiles can be found in their respective folders

## Sample Convolutions
![sample convolutions](images/convs.JPG)


## Performance Comparisons 

The following 2 plots benchmark the performance of each implementation and show how the performance varies with changes in image size and filter size. 
As either of these parameters increases, the time complexity increases, this makes sense since the convolution will be required to do a larger computation at each step.

Next, it is clear that in any of the parallelized approaches, the time taken by the convolution decreases. This is logical since multiple convolutions are happening simultaneously. 
The best performance was acheived by OpenMP. At high values, threading comes in at a very close second.

![timing1](images/timing1.jpeg)

![timing2](images/timing2.jpeg)

## Contact
- Yousif Khaireddin ykh@bu.edu
- Zhuofa (Marco) Chen zfchen@bu.edu
- William Martin wmarti@bu.edu
- Ihor Leshchyshyn ihorlesh@bu.edu
- 
