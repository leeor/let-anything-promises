module PromiseMap = {
  let let_ = (promise, fn) => Promise.map(fn, promise);
};

module PromiseBind = {
  let let_ = (promise, fn) => promise |> Promise.map(fn);
};

module PromiseJsMap = {
  let let_ = (promise, fn) =>
    promise |> Promise.map(fn) |> Promise.Js.toBsPromise;
};

module PromiseJsBind = {
  let let_ = (promise, fn) =>
    promise |> Promise.map(fn) |> Promise.Js.toBsPromise;
};

module JsPromiseMap = {
  let let_ = (promise, fn) =>
    promise |> Js.Promise.then_(x => fn(x) |> Js.Promise.resolve);
};

module JsPromiseBind = {
  let let_ = (promise, fn) => promise |> Js.Promise.then_(x => fn(x));
};
