$$
\begin{equation}
\begin{align}
gcd\left(x, y\right) &= gcd(y, x \bmod y) \\
proof: x &= aG \\
y &= bG \\
a \perp b \ \ \ \ & i.e.\ \ gcd(a,b) = 1 \\
x \bmod y &= (a - \lfloor \frac{a}{b} \rfloor b)G \\
(1) &\iff b \perp (a - \lfloor \frac{a}{b} \rfloor b)\\
&反证法即可
\end{align}
\end{equation}
$$

$$

\begin{align}
ax+by=c \ \text{有整数解} \iff & \ gcd(a,b) \mid c \\
\text{ext-gcd}(a,b) \rarr & \ \{x, y, G\} \\
\text{ext-gcd}(b,a\bmod b) \rarr & \ \{x', y', G\} \\
ax+by= & \ bx'+(a \bmod b)y' \\
     = & \ G \\
     = & \ bx' + (a - \lfloor \frac{a}{b} \rfloor b)G y' \\
     = & \ aGy' + b(x' - \lfloor \frac{a}{b} \rfloor G y') \\

\end{align}

$$

$$

A_n \otimes B_m = \sum_{k \in [0, n+m]} (\sum_{i + j = k} a_i * b_j) x^k

$$