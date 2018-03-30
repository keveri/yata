type item = {
  id: int,
  title: string,
  completed: bool
};

let component = ReasonReact.statelessComponent("Item");

let make = (~item, ~onToggle, _children) => {
  ...component,
  render: (_self) =>
    <div className="item" onClick=((_evt) => onToggle())>
      <MaterialUI.Checkbox
        checked=(item.completed)
      />
      (Helpers.str(item.title))
    </div>
}
