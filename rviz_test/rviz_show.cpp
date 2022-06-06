#include "rviz_show.h"
#include "rviz_widget.h"
#include "ui_rviz_widget.h"

rviz_show::rviz_show()
{
      int argc;
      char **argv;
      ros::init(argc,argv,"QRviz",ros::init_options::AnonymousName);
      //new docker for rviz
      rviz::RenderPanel *render_panel_=new rviz::RenderPanel;
      //form of cursor
      render_panel_->setCursor(Qt::PointingHandCursor);
      //add in rviz_layout
      ui->rviz_layout->addWidget(render_panel_);
      //new Object of rviz to control this rviz
      rviz::VisualizationManager* manager_=new rviz::VisualizationManager(render_panel_);
      //initial camera : zoom in/out, translation
      render_panel_->initialize(manager_->getSceneManager(),manager_);

      //manage tool of rviz
      rviz::ToolManager* tool_man;
      // slot() - rviz send a signal to rvviz itself slot()
      //       connect( tool_man, SIGNAL( toolAdded( Tool* )), this, SLOT( addTool( Tool* )));

      // Display
      manager_->initialize();
      manager_->removeAllDisplays();

      // set grid
      rviz::Display* grid_ = manager_->createDisplay( "rviz/Grid", "adjustable grid", true );
      ROS_ASSERT( grid_ != NULL );
      // Parameter
      grid_->subProp( "Line Style" )->setValue( "Billboards" );
      grid_->subProp( "Color" )->setValue(QColor(125,125,125));

      // set frame
      manager_->setFixedFrame("/morpheus_frame");

      // set PointCloud2
      rviz::Display* PCmap_ = manager_->createDisplay("rviz/PointCloud2", "PointCloud2", true);
      ROS_ASSERT( PCmap_ != NULL );
      PCmap_->subProp("Topic")->setValue("/merge_node/merged_points");
      PCmap_->subProp("Invert Rainbow")->setValue("true");
      PCmap_->subProp("Style")->setValue("Flat Squares");
      PCmap_->subProp("Size (m)")->setValue("0.01");
      PCmap_->subProp("Color Transformer")->setValue("FlatColor");
      PCmap_->subProp("Queue Size")->setValue("10");
      PCmap_->subProp("Alpha")->setValue("1");
      PCmap_->subProp("Color")->setValue("0,0,255");

      manager_->startUpdate();
}
