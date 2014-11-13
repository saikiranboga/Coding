import collections
import hashlib
import fractions
from sets import Set


def fastLongestPalindromes(seq):
    """
    Behaves identically to naiveLongestPalindrome (see below), but
    runs in linear time.
    """

    test = "";

    for i in seq:
        test = test + str(i) + " "
        
    seqLen = len(seq)
    l = []
    i = 0
    palLen = 0
    # Loop invariant: seq[(i - palLen):i] is a palindrome.
    # Loop invariant: len(l) >= 2 * i - palLen. The code path that
    # increments palLen skips the l-filling inner-loop.
    # Loop invariant: len(l) < 2 * i + 1. Any code path that
    # increments i past seqLen - 1 exits the loop early and so skips
    # the l-filling inner loop.

    while i < seqLen:
        # First, see if we can extend the current palindrome.  Note
        # that the center of the palindrome remains fixed.
        if i > palLen and seq[i - palLen - 1] == seq[i]:
            test = test + str(seq[(i-palLen-1):(i+1)]) + " "; 
            palLen += 2
            i += 1
            continue

        # The current palindrome is as large as it gets, so we append
        # it.
        l.append(palLen)

        # Now to make further progress, we look for a smaller
        # palindrome sharing the right edge with the current
        # palindrome.  If we find one, we can try to expand it and see
        # where that takes us.  At the same time, we can fill the
        # values for l that we neglected during the loop above. We
        # make use of our knowledge of the length of the previous
        # palindrome (palLen) and the fact that the values of l for
        # positions on the right half of the palindrome are closely
        # related to the values of the corresponding positions on the
        # left half of the palindrome.

        # Traverse backwards starting from the second-to-last index up
        # to the edge of the last palindrome.
        s = len(l) - 2
        e = s - palLen
        for j in xrange(s, e, -1):
            # d is the value l[j] must have in order for the
            # palindrome centered there to share the left edge with
            # the last palindrome.  (Drawing it out is helpful to
            # understanding why the - 1 is there.)
            d = j - e - 1

            # We check to see if the palindrome at l[j] shares a left
            # edge with the last palindrome.  If so, the corresponding
            # palindrome on the right half must share the right edge
            # with the last palindrome, and so we have a new value for
            # palLen.
            if l[j] == d: # *
                palLen = d
                # We actually want to go to the beginning of the outer
                # loop, but Python doesn't have loop labels.  Instead,
                # we use an else block corresponding to the inner
                # loop, which gets executed only when the for loop
                # exits normally (i.e., not via break).
                break

            # Otherwise, we just copy the value over to the right
            # side.  We have to bound l[i] because palindromes on the
            # left side could extend past the left edge of the last
            # palindrome, whereas their counterparts won't extend past
            # the right edge.
            l.append(min(d, l[j]))
        else:
            # This code is executed in two cases: when the for loop
            # isn't taken at all (palLen == 0) or the inner loop was
            # unable to find a palindrome sharing the left edge with
            # the last palindrome.  In either case, we're free to
            # consider the palindrome centered at seq[i].
            palLen = 1
            i += 1

    # We know from the loop invariant that len(l) < 2 * seqLen + 1, so
    # we must fill in the remaining values of l.

    # Obviously, the last palindrome we're looking at can't grow any
    # more.
    l.append(palLen)

    # Traverse backwards starting from the second-to-last index up
    # until we get l to size 2 * seqLen + 1. We can deduce from the
    # loop invariants we have enough elements.
    lLen = len(l)
    s = lLen - 2
    e = s - (2 * seqLen + 1 - lLen)
    for i in xrange(s, e, -1):
        # The d here uses the same formula as the d in the inner loop
        # above.  (Computes distance to left edge of the last
        # palindrome.)
        d = i - e - 1
        # We bound l[i] with min for the same reason as in the inner
        # loop above.
        l.append(min(d, l[i]))

#    return l
    return len(set(test.split()));



def count(s):
    
    N = len(s)
    hsh = {};

    test = ""

    for i in s:
        #if(str(i) not in hsh):
            #hsh[str(i)] = 1;
        test = test + str(i) + " "
        
    R = [[None]*(N+1) for _ in range(2)]
    s = "@" + s + "#";
    
    for j in range(0,2):
        R[j][0] = rp = 0;
        i = 1;
        while i <= N:
            while s[i-rp-1] == s[i+j+rp]:
                #print str(s[(i-rp-1):(i-rp-1)+(2*(rp+1)+j)])
                #if(str(s[(i-rp-1):(i-rp-1)+(2*(rp+1)+j)]) not in hsh ):
                    #hsh[ str(s[(i-rp-1):(i-rp-1)+(2*(rp+1)+j)]) ] = 1;
                test = test + str(s[(i-rp-1):(i-rp-1)+(2*(rp+1)+j)]) + " "
                rp += 1
            R[j][i] = rp
            k = 1
            while ( (R[j][i-k] != (rp-k)) and (k<rp) ):
                R[j][i+k] = min(R[j][i-k], rp-k);
                k += 1;
            rp = max(rp-k, 0);
            i += k;

    #s = s[1:N+1]

    #print hsh;

#    for i in range(1,N+1):
#        for j in range(0,2):
#            for rp in range(R[j][i], 0, -1):
#                if(str(s[(i-rp-1):(i-rp-1)+(2*rp+j)]) not in hsh ):
#                    hsh[ str(s[(i-rp-1):(i-rp-1)+(2*rp+j)]) ] = 1;

    return len(set(test.split()));

    #return len(hsh);

def main():
    s = str(raw_input());
    N = int(raw_input());
    T = len(s);

    #n = count(s);
    n = fastLongestPalindromes(s);
    k = N;
    k_2 = k/2;
    if(k%2 == 0):
        ans = k * pow(n,k_2);
        ans = ans + k*pow(n,k_2+1);
        
        tmp = 0;
        for p in range(1,k+1):
            tmp = tmp + pow(n,fractions.gcd(k,p));

        ans = ans + (2*tmp);
        ans = ans/(4*k);
        print ans;
    else:
        ans = k*pow(n,(k+1)/2);
        
        tmp = 0;
        for p in range(1,k+1):
            tmp = tmp + pow(n,fractions.gcd(k,p));

        ans = ans + tmp;
        ans = ans/(2*k);
        print ans;
    return 0;
main();
#print fastLongestPalindromes("aaba");
