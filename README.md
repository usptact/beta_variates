# libbeta
Sample from the Beta distribution

## Quickstart

Build the BA algorithm demo
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

Run the BA algorithm demo
```
$ ./beta_sample
```

You should see counts for each of the 10 bins.

## Advanced Usage

The current example uses the BA algorithm from [1].

Set parameters `a` and `b`.

Define the number of bins, default is 10.

Optionally, normalize counts by the total number of samples and plot.

## Credits
Ported Python code from [James McCaffrey's Blog](https://jamesmccaffrey.wordpress.com/2019/03/29/sampling-from-the-beta-distribution-using-python/beta_sampling_python/)

## References
[[1]](https://dl.acm.org/doi/pdf/10.1145/359460.359482) R. C. H. Cheng, Generating Beta Variates with Nonintegral Shape Parameters, Communications of the ACM, Vol. 21, Issue 4, pp. 317-322, 1978.
