let component = ReasonReact.statelessComponent("Main");

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <Header title="Yet Another Todo App" />
      <Content />
    </div>
};
