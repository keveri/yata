let component = ReasonReact.statelessComponent("YATA");

let make = (~title, _children) => {
  ...component,
  render: self =>
    <div className="app">
      <div className="title">
        (ReasonReact.stringToElement(title))
      </div>
      <div className="items">
        (ReasonReact.stringToElement("Empty"))
      </div>
    </div>,
};
