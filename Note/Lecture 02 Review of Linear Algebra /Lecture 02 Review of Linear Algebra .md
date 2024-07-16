# Lecture 02 Review of Linear Algebra 

## Vectors

### Vector Normalization

### Vector Addition

### Cartesian Coordinates

### Vector Multiplication

* Dot product
* Cross product
* Orthonormal bases and coordinate frames

## Matrices

### Matrix-Matrix Multiplication

### Matrix-Vector Multiplication

### Transpose of a Matrix

$$
\left[
\begin{matrix}
1 & 2\\
3 & 4\\
5 & 6
\end{matrix}
\right]^T

=

\left[
\begin{matrix}
1 & 3 & 5\\
2 & 4 & 6
\end{matrix}
\right]
$$

$$
(AB)^T=B^TA^T
$$

### Identity Matrix and Inverses

$$
I_{3 \times 3}

=

\left[
\begin{matrix}
1 & 0 & 0\\
0 & 1 & 0\\
0 & 0 & 1
\end{matrix}
\right]
$$

$$
AA^{-1}=A^{-1}A=I
$$

$$
(AB)^{-1}=B^{-1}A^{-1}
$$

### Vector multipcation in Matrix form

* Dot product

$$
\vec{a} \cdot \vec{b} = \vec{a}^T \cdot \vec{b}

=

\left[
\begin{matrix}
x_a & y_a & z_a
\end{matrix}
\right]

\left[
\begin{matrix}
x_b\\ 
y_b\\
z_b
\end{matrix}
\right]
$$

* Cross product

$$
\vec{a} \times \vec{b} = A * \vec{b}

=

\left[
\begin{matrix}
0 & -z_a & y_a\\
z_a & 0 & -x_a\\
-y_a & x_a & o
\end{matrix}
\right]

\left[
\begin{matrix}
x_b\\ 
y_b\\
z_b
\end{matrix}
\right]
$$