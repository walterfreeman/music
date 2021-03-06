### Preliminaries
We want to demonstrate that when an input signal goes through a nonlinear process -- the distortion from an amplifier or the nonlinear motion of the mechanism of the middle ear -- new frequencies equal to sums and differences of the input frequencies are created.

### A single input tone

Suppose that the input signal $s(t)$ is a pure sinusoid, i.e. $$s(t) = Ae^{i\omega t}.$$

We are interested in the frequency spectrum of a nonlinear transform of this, i.e. the decomposition into component frequencies of $$f(s(t)),$$ where $f(x)$ is the nonlinear response function.

We can decompose $f(x)$ into a Taylor series. Removing any DC offset, then 

$$f(x) = xf'(0) + \frac{1}{2}x^2f''(0)+\frac{1}{6}x^3f'''(0)+...$$

which we rewrite as

$$f(x) = Lx + Qx^2+Cx^3+...$$

where $L$, $Q$, and $C$ are the linear, quadratic, and cubic coefficients of the nonlinear function. There are of course more of these; I separate out Q and C because certain symmetric nonlinearities (for instance, the response of an amplifier) might have $Q=0$.

and then

$$f(Ae^{i\omega t}) = ALe^{i\omega t} + A^2Qe^{2i\omega t} + A^3Ce^{3i\omega t}+...$$

Other terms are present as well; this indicates that the heterodyne mechanism generates tones that are integer multiples of the fundamental, with only odd terms generated by symmetric nonlinearities; the relative amplitude of these distortion frequencies increases as the input amplitude increases.

### Two input tones

Now suppose that the input signal $s(t)$ is a combination of two pure sinusoids, i.e. $$s(t) = Ae^{i\omega_1 t}+Be^{i\omega_2 t}.$$

Then 


$$f(Ae^{i\omega_1 t}+Be^{i\omega_2 t}) = ALe^{i\omega_1 t} + A^2Qe^{2i\omega_1 t} + A^3Ce^{3i\omega_1 t}+ BLe^{i\omega_2 t} + B^2Qe^{2i\omega_2 t} + B^3Ce^{3i\omega_2 t}s+2ABQe^{i\omega$$