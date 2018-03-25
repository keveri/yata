let component = ReasonReact.statelessComponent("Content");

let contentPageStyle = ReactDOMRe.Style.make(
  ~textAlign="center",
  ~display="inline-block",
  ~marginTop="1em",
  ~width="100%",
  ~height="4em",
  ()
);

let make = _children => {
  ...component,
  render: _self =>
    <MaterialUI.Paper style=contentPageStyle>
      (ReasonReact.stringToElement("Content will be here!"))
    </MaterialUI.Paper>
};
