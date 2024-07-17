# Lecture 04 Transformation Cont

## 3D Transformations

### Homogeneous Coordinates

* 3D point = $( x,y,z,1 )^T$
* 3D vector = $( x,y,z,0 )^T$

In general, $( x,y,z,w )(w \neq 0)$ is the 3D point $( x/w,y/w,z/w )$ .

### Translation Matrix

$$
T(t_x,t_y,t_z)=

\left[
\begin{matrix}
1 & 0 & 0 & t_x\\
0 & 1 & 0 & t_y\\
0 & 0 & 1 & t_z\\
0 & 0 & 0 & 1
\end{matrix}
\right]
$$

### Scale Matrix

$$
S(s_x,s_y,s_z)=

\left[
\begin{matrix}
s_x & 0 & 0 & 0\\
0 & s_y & 0 & 0\\
0 & 0 & s_z & 0\\
0 & 0 & 0 & 1
\end{matrix}
\right]
$$

### Rotation arount x-axis,y-axis,z-axis

$$
R_x(\alpha)=

\left[
\begin{matrix}
1 & 0 & 0 & 0\\
0 & \cos(\alpha) & -\sin(\alpha) & 0\\
0 & \sin(\alpha) & \cos(\alpha) & 0\\
0 & 0 & 0 & 1
\end{matrix}
\right]
$$

$$
R_y(\alpha)=

\left[
\begin{matrix}
\cos(\alpha) & 0 & \sin(\alpha) & 0\\
0 & 1 & 0 & 0\\
-\sin(\alpha) & 0 & \cos(\alpha) & 0\\
0 & 0 & 0 & 1
\end{matrix}
\right]
$$

$$
R_z(\alpha)=

\left[
\begin{matrix}
\cos(\alpha) & -\sin(\alpha) & 0 & 0\\
\sin(\alpha) & \cos(\alpha) & 0 & 0\\
0 & 0 & 1 & 0\\
0 & 0 & 0 & 1
\end{matrix}
\right]
$$

### Euler angles

$$
R_{xyz}(\alpha,\beta,\gamma)=R_x(\alpha)R_y(\beta)R_z(\gamma)
$$

$$
R=

\left[
\begin{matrix}
1 & 0 & 0 & 0\\
0 & \cos(\alpha) & -\sin(\alpha) & 0\\
0 & \sin(\alpha) & \cos(\alpha) & 0\\
0 & 0 & 0 & 1
\end{matrix}
\right]

\left[
\begin{matrix}
\cos(\alpha) & 0 & \sin(\alpha) & 0\\
0 & 1 & 0 & 0\\
-\sin(\alpha) & 0 & \cos(\alpha) & 0\\
0 & 0 & 0 & 1
\end{matrix}
\right]

\left[
\begin{matrix}
\cos(\alpha) & -\sin(\alpha) & 0 & 0\\
\sin(\alpha) & \cos(\alpha) & 0 & 0\\
0 & 0 & 1 & 0\\
0 & 0 & 0 & 1
\end{matrix}
\right]
$$

### Rodrigues' Rotation Formula

Rotation by angle $\alpha$ around axis $n$ :

$$
R(n,\alpha) = \cos(\alpha)I + (1-\cos(\alpha))nn^T + \sin(\alpha)
\underbrace{
\left(
\begin{matrix}
0 & -n_z & n_y\\
n_z & 0 & -n_x\\
-n_y & n_x & 0
\end{matrix}
\right)
}_N
$$

## Viewing transformation

### View/Camera transformation

* Define the camera first
  * Position $\vec{e}$
  * Look-at/gaze direction $\hat{g}$
  * Up direction $\hat{t}$

* How about that we always transform the camera to
  * The origin,up at $Y$ ,look at $-Z$
  * And transform the objects along with the camera

* Transform the camera by $M_{view}$
  * Located at the origin,up at $Y$ ,look at $-Z$

* $M_{view}$ in math
  * Translates $e$ to origin
  * Rotates $\hat{g}$ to $-Z$
  * Rotates $\hat{t}$ to $Y$
  * Rotates $(\hat{g} \times \hat{t})$ to $X$

* $M_{view}$ in math
  * $M_{view}=R_{view}T_{view}$
  * Translate $e$ to origin
    $$
    T_{view}=
    \left[
    \begin{matrix}
    1 & 0 & 0 & -x_{\vec{e}}\\
    0 & 1 & 0 & -y_{\vec{e}}\\
    0 & 0 & 1 & -z_{\vec{e}}\\
    0 & 0 & 0 & 1
    \end{matrix}
    \right]
    $$
  * Rotate $\hat{g}$ to $-Z$ , $\hat{t}$ to $Y$ , $(\hat{g} \times \hat{t})$ to $X$
  * Consider its inverse rotation: $X$ to $(\hat{g} \times \hat{t})$ ,$Y$ to $\hat{t}$ , $Z$ to $- \hat{g}$
    $$
    R^{-1}_{view}=
    \left[
    \begin{matrix}
    x_{\hat{g} \times \hat{t}} & x_{\hat{t}} & x_{-\hat{g}} & 0\\
    y_{\hat{g} \times \hat{t}} & y_{\hat{t}} & y_{-\hat{g}} & 0\\
    z_{\hat{g} \times \hat{t}} & z_{\hat{t}} & z_{-\hat{g}} & 0\\
    0 & 0 & 0 & 1
    \end{matrix}
    \right]
    $$
    $$
    R_{view}=
    \left[
    \begin{matrix}
    x_{\hat{g} \times \hat{t}} & y_{\hat{g} \times \hat{t}} & z_{\hat{g} \times \hat{t}} & 0\\
    x_{\hat{t}} & y_{\hat{t}} & z_{\hat{t}} & 0\\
    x_{-\hat{g}} & y_{-\hat{g}} & z_{-\hat{g}} & 0\\
    0 & 0 & 0 & 1
    \end{matrix}
    \right]
    $$

### Projection transformation

#### Orthographic projection

* Understanding
  * Camera located at origin,looking at $-Z$, up at $Y$ 
  * Drop $Z$ coordinate
  * Translate and scale the resulting rectangle to $[-1,1]^2$
* In general
  * We want to map a cuboid $[left,right] \times [bottom,top] \times [far,near]$ to the "canonical" cube $[-1,1]^3$
* Transformation matrix
  $$
  M_{ortho}=
  \left[
  \begin{matrix}
  \frac{2}{r-l} & 0 & 0 & 0\\
  0 & \frac{2}{t-b} & 0 & 0\\
  0 & 0 & \frac{2}{n-f} & 0\\
  0 & 0 & 0 & 1
  \end{matrix}
  \right]
  $$


#### Perspective projection

