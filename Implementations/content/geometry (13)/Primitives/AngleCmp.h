/**
 * Description: sorts points in ccw order about origin, 
 	* \texttt{atan2} returns real in $(-\pi,\pi]$ so points on negative $x$-axis come last
 * Usage: 
 	* vP v;
 	* sort(all(v),[](P a, P b) { return 
 		atan2(a.s,a.f) < atan2(b.s,b.f); });
 	* sort(all(v),angleCmp); // should give same result
 * Verification: https://codeforces.com/contest/1284/submission/68175790
 	* https://codeforces.com/contest/1284/submission/68207607 
 	* (don't use atan2, weird stuff happens!)
 */

#include "Point.h"

bool half(P x) { return x.s == 0 ? x.f < 0 : x.s > 0; }
bool angleCmp(P a, P b) { 
	bool A = half(a), B = half(b);
	return A == B ? cross(a,b) > 0 : A < B;
}