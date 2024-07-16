# Lecture 03 Transformation

## 2D transformations

### Homogeneous Coordinates

Add a third coordinate(w-coordinate)
* 2D point = $( x,y,1 )^T$
* 2D vector = $( x,y,0 )^T$

### Translation Matrix

$$
T(t_x,t_y)=

\left[
\begin{matrix}
1 & 0 & t_x\\
0 & 1 & t_y\\
0 & 0 & 1
\end{matrix}
\right]
$$

$$
\left[
\begin{matrix}
x^{'}\\ 
y^{'}\\
w^{'}
\end{matrix}
\right]

=

\left[
\begin{matrix}
1 & 0 & t_x\\
0 & 1 & t_y\\
0 & 0 & 1
\end{matrix}
\right]

\left[
\begin{matrix}
x\\ 
y\\
1
\end{matrix}
\right]

=

\left[
\begin{matrix}
x+t_x\\ 
y+t_y\\
1
\end{matrix}
\right]
$$

In homogeneous coordinates, $\left[ \begin{matrix} x\\ y\\ w \end{matrix} \right]$ is the 2D point $\left[ \begin{matrix} x/w\\ y/w\\ 1 \end{matrix} \right]$ , $w \neq 0$ .

### Scale Matrix

$$
S(s_x,s_y)=

\left[
\begin{matrix}
s_x & 0 & 0\\
0 & s_y & 0\\
0 & 0 & 1
\end{matrix}
\right]
$$

### Rotation Matrix

$$
R(\alpha)=

\left[
\begin{matrix}
\cos(\alpha) & - \sin(\alpha) & 0\\
\sin(\alpha) & \cos(\alpha) & 0\\
0 & 0 & 1
\end{matrix}
\right]
$$

### Inverse Transform

$$
M^{-1}
$$

$M^{-1}$ is the inverse of transform $M$ in both a matrix and geometric sense .

### Composing Transforms

Transform ordering matters!

$$
R_{45} \cdot T_{(1,0)} \neq T_{(1,0)} \cdot R_{45}
$$

