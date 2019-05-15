# Demo of let%Anything with Promises

The [test](__tests__/Demo_test.re) code showcases the usage of let%Anything for creating helpers for dealing with promises in ReasonML.

## Contents

There are helpers in this demo for both `Js.Promise` and `Repromise`. For each of these, there's a `map` helper and a monadic `bind` helper. Additionally, for `Repromise`, there are also a `map` and `bind` helpers then convert to `Js.Promise`.
