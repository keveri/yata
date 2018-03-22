let component = ReasonReact.statelessComponent("Page");

let make = (~content, _children) => {
  ...component,
  render: self =>
      (ReasonReact.stringToElement(content))
};
