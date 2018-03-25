let component = ReasonReact.statelessComponent("Header");

let make = (~title, _children) => {
  ...component,
  render: self =>
    <MaterialUI.AppBar position="static" color="default">
      <MaterialUI.Toolbar>
        <MaterialUI.Typography
          _type="title" color=MaterialUI.Typography.Color.Inherit>
          (ReasonReact.stringToElement(title))
        </MaterialUI.Typography>
      </MaterialUI.Toolbar>
    </MaterialUI.AppBar>
};
