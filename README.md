# NAME

Math::Int128 - Manipulate 128 bits integers in Perl

# SYNOPSIS

    use Math::Int128 qw(int128);

    my $i = int128(1);
    my $j = $i << 100;
    my $k = int128("1234567890123456789000000");
    print($i + $j * 1000000);

# DESCRIPTION

This module adds support for 128 bit integers, signed and unsigned, to
Perl.

In order to compile this module, GCC 4.4 or later is required.

# API

See [Math::Int64](https://metacpan.org/pod/Math::Int64). This module provides a similar set of functions,
just `s/64/128/g` ;-)

Besides that, as object allocation and destruction has been found to
be a bottleneck, an alternative set of operations that use their first
argument as the output (instead of the return value) is also
provided.

They are as follows:

    int128_inc int128_dec int128_add int128_sub int128_mul int128_pow
    int128_div int128_mod int128_divmod int128_and int128_or int128_xor
    int128_left int128_right int128_not int128_neg

and the corresponding `uint128` versions.

For instance:

    my $a = int128("1299472960684039584764953");
    my $b = int128("-2849503498690387383748");
    my $ret = int128();
    int128_mul($ret, $a, $b);
    int128_inc($ret, $ret); # $ret = $ret + 1
    int128_add($ret, $ret, "12826738463");
    say $ret;

`int128_divmod` returns both the result of the division and the remainder:

    my $ret = int128();
    my $rem = int128();
    int128_divmod($ret, $rem, $a, $b);

# C API

The module provides a C API that allows to wrap/unwrap int128\_t and
uint128\_t values from other modules written in C/XS.

It is identical to that provided by [Math::Int64](https://metacpan.org/pod/Math::Int64) so read the
documentation there in order to know how to use it.

# TODO

Support more operations as log2, pow, etc.

# BUGS AND SUPPORT

The C API feature is experimental.

This module requires 128bit integer support from the C
compiler. Currently only gcc 4.4 and later are supported. If you have
a different compiler that also supports 128bit integers get in touch
with me in order to have it supported.

You can send me bug reports by email to the address that appears below
or use the CPAN RT bug tracking system available at
[http://rt.cpan.org](http://rt.cpan.org).

The source for the development version of the module is hosted at
GitHub: [https://github.com/salva/p5-Math-Int128](https://github.com/salva/p5-Math-Int128).

## My wishlist

If you like this module and you're feeling generous, take a look at my
Amazon Wish List: [http://amzn.com/w/1WU1P6IR5QZ42](http://amzn.com/w/1WU1P6IR5QZ42)

# SEE ALSO

[Math::Int64](https://metacpan.org/pod/Math::Int64), [Math::GMP](https://metacpan.org/pod/Math::GMP), [Math::GMPn](https://metacpan.org/pod/Math::GMPn).

[http://perlmonks.org/?node\_id=886488](http://perlmonks.org/?node_id=886488).

# COPYRIGHT AND LICENSE

Copyright © 2007, 2009, 2011-2014 by Salvador Fandiño (sfandino@yahoo.com)

Copyright © 2014 by Dave Rolsky

This library is free software; you can redistribute it and/or modify
it under the same terms as Perl itself, either Perl version 5.10.1 or,
at your option, any later version of Perl 5 you may have available.
