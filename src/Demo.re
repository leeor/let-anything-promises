module RepromiseMap = {
  let let_ = (promise, fn) => Repromise.map(fn, promise);
};

module RepromiseBind = {
  let let_ = (promise, fn) => promise |> Repromise.andThen(fn);
};

module RepromiseJsMap = {
  let let_ = (promise, fn) =>
    promise |> Repromise.map(fn) |> Repromise.Rejectable.toJsPromise;
};

module RepromiseJsBind = {
  let let_ = (promise, fn) =>
    promise |> Repromise.andThen(fn) |> Repromise.Rejectable.toJsPromise;
};

module JsPromiseMap = {
  let let_ = (promise, fn) =>
    promise |> Js.Promise.then_(x => fn(x) |> Js.Promise.resolve);
};

module JsPromiseBind = {
  let let_ = (promise, fn) => promise |> Js.Promise.then_(x => fn(x));
};
