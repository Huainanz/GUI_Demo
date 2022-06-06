#include "qrviz_widget.h"
#include "ui_qrviz_widget.h"

QrvizWidget::QrvizWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QrvizWidget)
{
    ui->setupUi(this);
       int argc;
       char **argv;
       //ros::init(argc,argv,"QRviz",ros::init_options::AnonymousName);
       //new docker
       rviz::RenderPanel *render_panel_=new rviz::RenderPanel;
       //form of cursor
       render_panel_->setCursor(Qt::PointingHandCursor);
       //add in rviz_wg
       //ui->formLayout->addWidget(render_panel_);
       //initial Object
       rviz::VisualizationManager* manager_=new rviz::VisualizationManager(render_panel_);
       //initial camera : zoom in/out, translation
       render_panel_->initialize(manager_->getSceneManager(),manager_);

       //manage tool of rviz
       rviz::ToolManager* tool_man;
       // slot() - rviz send a signal to rvviz itself slot()
//       connect( tool_man, SIGNAL( toolAdded( Tool* )), this, SLOT( addTool( Tool* )));
//       connect( tool_man, SIGNAL( toolRemoved( Tool* )), this, SLOT( removeTool( Tool* )));
//       connect( tool_man, SIGNAL( toolRefreshed( Tool* )), this, SLOT( refreshTool( Tool* )));
//       connect( tool_man, SIGNAL( toolChanged( Tool* )), this, SLOT( indicateToolIsCurrent( Tool* )));
       manager_->initialize();
       manager_->removeAllDisplays();

       rviz::Display* grid_ = manager_->createDisplay( "rviz/Grid", "adjustable grid", true );
       ROS_ASSERT( grid_ != NULL );

       // Configure the GridDisplay the way we like it.
       grid_->subProp( "Line Style" )->setValue( "Billboards" );

       grid_->subProp( "Color" )->setValue(QColor(125,125,125));
       manager_->startUpdate();
}

QrvizWidget::~QrvizWidget()
{
    delete ui;
}
