#ifndef COMPOSITING_HPP_
#define COMPOSITING_HPP_

#include <vector>
#include <opencv2/stitching/stitcher.hpp>

class Compositing {

public:

	static void warpImages(const std::vector<cv::Mat>& imgs, const std::vector<cv::detail::CameraParams>& cameras,
		std::vector<cv::Mat>& warped_imgs, std::vector<cv::Point>& warped_corners, std::vector<cv::Mat>& warped_masks);

	static void voronoiSeamEstimation(const std::vector<cv::Mat>& imgs, const std::vector<cv::Point>& corners,
		std::vector<cv::Mat>& masks);

	static void dynamicProgrammingSeamEstimation(const std::vector<cv::Mat>& imgs, const std::vector<cv::Point>& corners,
		std::vector<cv::Mat>& masks);

	static void graphCutSeamEstimation(const std::vector<cv::Mat>& imgs, const std::vector<cv::Point>& corners,
		std::vector<cv::Mat>& masks, int cost_type=cv::detail::GraphCutSeamFinder::COST_COLOR);

private:

	static void estimateSeams(const std::vector<cv::Mat>& imgs, const std::vector<cv::Point>& corners,
		std::vector<cv::Mat>& masks, cv::detail::SeamFinder* seam_finder);

};

#endif /* COMPOSITING_HPP_ */