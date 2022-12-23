# libbeta
Sample from the Beta distribution

## Quickstart

Build sample programs
* build a histogram of sample counts (10 bins)
* stream of samples

```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

Run the BA algorithm demo
```
$ ./sample_hist 1.0 2.0
1821 1679 1602 1274 1117 890 756 475 278 108 

$ ./sample_stream 1.0 2.0
0.130430
0.622695
0.473631
...
<Ctrl-C>
```

## Advanced Usage

1. Include the header `libbeta.h` into your program

2. Set parameters `a` and `b` for the Beta distribution to sample from

3. Call `beta_sample_BA(a, b)` to get a sample

## Credits
Ported Python code from [James McCaffrey's Blog](https://jamesmccaffrey.wordpress.com/2019/03/29/sampling-from-the-beta-distribution-using-python/beta_sampling_python/)

## References
[[1]](https://dl.acm.org/doi/pdf/10.1145/359460.359482) R. C. H. Cheng, Generating Beta Variates with Nonintegral Shape Parameters, Communications of the ACM, Vol. 21, Issue 4, pp. 317-322, 1978.
