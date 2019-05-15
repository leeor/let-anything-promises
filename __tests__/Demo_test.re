open Jest;
open Expect;
open Demo;

describe("Repromise", () => {
  describe("let%RepromiseJsMap", () =>
    testPromise("should map a promise's value to a Js.Promise", () => {
      let p = 1 |> Repromise.resolved;
      let%RepromiseJsMap v = p;
      expect(v) |> toBe(1);
    })
  );

  describe("let%RepromiseMap", () =>
    testPromise("should map a promise's value", () => {
      let p = 1 |> Repromise.resolved;
      let mapped = {
        let%RepromiseMap mapped = p;
        mapped + 1;
      };
      let%RepromiseJsMap v = mapped;
      expect(v) |> toBe(2);
    })
  );

  describe("let%RepromiseJsBind", () =>
    testPromise(
      "should perform a monadic bind on a promise's value to a Js.Promise", () => {
      let p = 1 |> Repromise.resolved;
      let%RepromiseJsBind v = p;
      expect(v) |> toBe(1) |> Repromise.resolved;
    })
  );

  describe("let%RepromiseBind", () => {
    testPromise("should perform a monadic bind on a promise's value", () => {
      let p = 1 |> Repromise.resolved;
      let mapped = {
        let%RepromiseBind mapped = p;
        Repromise.resolved(mapped + 1);
      };
      let%RepromiseJsBind v = mapped;
      expect(v) |> toBe(2) |> Repromise.resolved;
    });

    testPromise(
      "should perform a sequential monadic bind on a promise's value", () => {
      let p = 1 |> Repromise.resolved;
      let mapped = {
        let%RepromiseBind mapped = p;
        Repromise.resolved(mapped + 1);
      };
      let mappedOver = {
        let%RepromiseBind mappedOver = mapped;
        Repromise.resolved(mappedOver + 1);
      };
      let%RepromiseJsBind v = mappedOver;
      expect(v) |> toBe(3) |> Repromise.resolved;
    });
  });
});

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
