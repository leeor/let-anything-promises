open Jest;
open Expect;
open Demo;

// describe("Promise", () => {
//   describe("let%PromiseJsMap", () =>
//     testPromise("should map a promise's value to a Js.Promise", () => {
//       let p = 1 |> Promise.resolved;
//       let%PromiseJsMap v = p;
//       expect(v) |> toBe(1);
//     })
//   );

//   describe("let%PromiseMap", () =>
//     testPromise("should map a promise's value", () => {
//       let p = 1 |> Promise.resolved;
//       let mapped = {
//         let%PromiseMap mapped = p;
//         mapped + 1;
//       };
//       let%PromiseJsMap v = mapped;
//       expect(v) |> toBe(2);
//     })
//   );

//   describe("let%PromiseJsBind", () =>
//     testPromise(
//       "should perform a monadic bind on a promise's value to a Js.Promise", () => {
//       let p = 1 |> Promise.resolved;
//       let%PromiseJsBind v = p;
//       expect(v) |> toBe(1) |> Promise.resolved;
//     })
//   );

//   describe("let%PromiseBind", () => {
//     testPromise("should perform a monadic bind on a promise's value", () => {
//       // let p = 1 |> Promise.resolved;
//       let p = Promise.resolved(1)
//       let mapped = {
//         let%PromiseBind mapped = p->Promise.get(s => Js.log(s));
//         Promise.resolved(mapped + 1);
//       };
//       let%PromiseJsBind v = mapped;
//       expect(v) |> toBe(2) |> Promise.resolved;
//     });

//     testPromise(
//       "should perform a sequential monadic bind on a promise's value", () => {
//       let p = 1 |> Promise.resolved;
//       let mapped = {
//         let%PromiseBind mapped = p;
//         Promise.resolved(mapped + 1);
//       };
//       let mappedOver = {
//         let%PromiseBind mappedOver = mapped;
//         Promise.resolved(mappedOver + 1);
//       };
//       let%PromiseJsBind v = mappedOver;
//       expect(v) |> toBe(3) |> Promise.resolved;
//     });
//   });
// });

describe("JsPromise", () => {
  testPromise("should map a promise's value", () => {
    let p = 1 |> Js.Promise.resolve;
    let%JsPromiseMap v = p;
    expect(v) |> toBe(1);
  });

  testPromise("should sequentially map a promise's value", () => {
    let p = 1 |> Js.Promise.resolve;
    let mapped = {
      let%JsPromiseMap mapped = p;
      mapped + 1;
    };
    let mappedOver = {
      let%JsPromiseMap mappedOver = mapped;
      mappedOver + 1;
    };
    let%JsPromiseMap v = mappedOver;
    expect(v) |> toBe(3);
  });

  testPromise(
    "should perform a sequential monadic bind on a promise's value", () => {
    let p = 1 |> Js.Promise.resolve;
    let mapped = {
      let%JsPromiseMap mapped = p;
      mapped + 1;
    };
    let mappedOver = {
      let%JsPromiseMap mappedOver = mapped;
      mappedOver + 1;
    };
    let%JsPromiseBind v = mappedOver;
    expect(v) |> toBe(3) |> Js.Promise.resolve;
  });
});
