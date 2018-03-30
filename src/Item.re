type item = {
  title: string,
  completed: bool
};

let component = ReasonReact.statelessComponent("Item");

let make = (~item, _children) => {
  ...component,
  render: (_self) =>
    <div className="item">
      <input
        _type="checkbox"
        checked=(Helpers.bool(item.completed))
      />
      (Helpers.str(item.title))
    </div>
}
